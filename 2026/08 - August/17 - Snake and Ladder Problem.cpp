class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int total = n * n;
        vector<int> jump(total + 1, 0);
        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }
        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }
        vector<bool> vis(total + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;
        while (!q.empty()) {
            auto [cur, step] = q.front();
            q.pop();
            if (cur == total) {
                return step;
            }
            for (int d = 1; d <= 6; d++) {
                int next = cur + d;
                if (next > total) {
                    continue;
                }
                if (jump[next] != 0) {
                    next = jump[next];
                }
                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, step + 1});
                }
            }
        }
        return -1;
    }
};
