class Solution {
private:
    int n;
    vector<vector<int>> dp;
    int f(int i, int prev, vector<vector<int>>& mat) {
        if (i == n) {
            return 0;
        }
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        int cost = INT_MAX;
        for (int j = 0; j < 3; j++) {
            if (j == prev) {
                continue;
            }
            cost = min(cost, mat[i][j] + f(i + 1, j, mat));
        }
        return dp[i][prev + 1] = cost;
    }
public:
    int minCost(vector<vector<int>>& mat) {
        n = mat.size();
        dp.assign(n + 1, vector<int> (4, -1));
        return f(0, -1, mat);
    }
};
