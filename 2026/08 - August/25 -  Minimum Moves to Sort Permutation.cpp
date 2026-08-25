class Solution {
public:
    int minMoves(vector<int>& a) {
        int n = a.size();
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[a[i]] = i;
        }
        int cur_len = 1;
        int max_len = 1;
        for (int i = 2; i <= n; i++) {
            if (pos[i] > pos[i - 1]) {
                cur_len++;
            } else {
                cur_len = 1;
            }
            max_len = max(max_len, cur_len);
        }
        return n - max_len;
    }
};
