class Solution {
private:
    int dp[12][12];
    int f(int ind, int prev, int n, int m) {
        if (ind == n) {
            return 1;
        }
        if (dp[ind][prev] != -1) {
            return dp[ind][prev];
        }
        int ans = 0;
        for (int x = 1; x <= m; x++) {
            if (ind == 0 || x % prev == 0 || prev % x == 0) {
                ans += f(ind + 1, x, n, m);
            }
        }
        return dp[ind][prev] = ans;
    }
public:
    int count(int n, int m) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, n, m);
    }
};
