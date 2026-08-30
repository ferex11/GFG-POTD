class Solution {
public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int q = rank.size();
        vector<vector<int>> queries(q, vector<int> (2));
        for (int i = 0; i < q; i++) {
            queries[i][0] = rank[i];
            queries[i][1] = i;
        }
        sort(queries.begin(), queries.end());
        vector<int> ans(q);
        int i = 0;
        int cnt = 0;
        for (auto& it : queries) {
            int x = it[0];
            int original_index = it[1];
            while (i < l.size()) {
                int sz = r[i] - l[i] + 1;
                if (x <= cnt + sz) {
                    int marks = l[i] + (x - cnt - 1);
                    ans[original_index] = marks;
                    break;
                }
                cnt += sz;
                i++;
            }
        }
        return ans;
    }
};
