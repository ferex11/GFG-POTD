class Solution {
private:
    const long long mod = 1e9 + 7;
public:
    int countSubsequences(string& s, int n) {
        vector<long long> dp(n, 0);
        for (char c : s) {
            int cur_digit = c - '0';
            vector<long long> new_dp = dp;
            int rem = cur_digit % n;
            new_dp[rem] = (new_dp[rem] + 1) % mod;
            for (int r = 0; r < n; r++) {
                int new_rem = (r * 10 + cur_digit) % n;
                new_dp[new_rem] = (new_dp[new_rem] + dp[r]) % mod;
            }
            dp = new_dp;
        }
        return dp[0];
    }
};
