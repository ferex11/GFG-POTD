// Recursion
class Solution {
private:
    int n;
    int f(int r, int c, vector<vector<int>>& mat) {
        if (r == n - 1) {
            return mat[r][c];
        }
        int best = 0;
        for (int nc = 0; nc < n; nc++) {
            if (nc == c) {
                continue;
            }
            best = max(best, f(r + 1, nc, mat));
        }
        return mat[r][c] + best;
    }
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        n = mat.size();
        int ans = 0;
        for (int c = 0; c < n; c++) {
            ans = max(ans, f(0, c, mat));
        }
        return ans;
    }
};

// Memoization
class Solution {
private:
    int n;
    int dp[1001[1001];
    int f(int r, int c, vector<vector<int>>& mat) {
        if (r == n - 1) {
            return mat[r][c];
        }
        if (dp[r][c] != -1) {
          return dp[r][c];
        }
        int best = 0;
        for (int nc = 0; nc < n; nc++) {
            if (nc == c) {
                continue;
            }
            best = max(best, f(r + 1, nc, mat));
        }
        return dp[r][c] = mat[r][c] + best;
    }
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        n = mat.size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int c = 0; c < n; c++) {
            ans = max(ans, f(0, c, mat));
        }
        return ans;
    }
};

// Tabulation
class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for (int c = 0; c < n; c++) {
            dp[n - 1][c] = mat[n - 1][c];
        }
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
                int best = 0;
                for (int nc = 0; nc < n; nc++) {
                    if (nc == c) {
                        continue;
                    }
                    best = max(best, dp[r + 1][nc]);
                }
                dp[r][c] = mat[r][c] + best;
            }
        }
        int ans = 0;
        for (int c = 0; c < n; c++) {
            ans = max(ans, dp[0][c]);
        }
        return ans;
    }
};

// Space Optimization
class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> prev(n), cur(n);
        for (int c = 0; c < n; c++) {
            prev[c] = mat[n - 1][c];
        }
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
                int best = 0;
                for (int nc = 0; nc < n; nc++) {
                    if (nc == c) {
                        continue;
                    }
                    best = max(best, prev[nc]);
                }
                cur[c] = mat[r][c] + best;
            }
            prev = cur;
        }
        int ans = 0;
        for (int c = 0; c < n; c++) {
            ans = max(ans, prev[c]);
        }
        return ans;
    }
};
