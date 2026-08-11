class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int r = q[0];
            int c = q[1];
            int low = 0;
            int high = min({r, c, n - r - 1, m - c - 1});
            int best = -1;
            while (low <= high) {
                int mid = (low + high) >> 1;
                int top = r - mid;
                int bottom = r + mid;
                int left = c - mid;
                int right = c + mid;
                int ones = prefix[bottom + 1][right + 1] - prefix[top][right + 1] - prefix[bottom + 1][left] + prefix[top][left];
                if (ones <= k) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans.push_back(2 * best + 1);
        }
        return ans;
    }
};
