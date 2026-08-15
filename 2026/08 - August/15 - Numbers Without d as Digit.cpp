// Brute force approach
class Solution {
public:
    int countWithout(int n, int d) {
        int cnt = 0;
        auto check = [&](int x) -> bool {
            while (x > 0) {
                int digit = x % 10;
                if (x == d) {
                    return false;
                }
                x /= 10;
            }
            return true;
        };
        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};

// Optimal Approach - Digit DP
class Solution {
private:
    int dp[11][2][2];
    int f(int ind, int tight, int started, string& s, int d) {
        if (ind == s.size()) {
            return 1;
        }
        if (dp[ind][tight][started] != -1) {
            return dp[ind][tight][started];
        }
        int ans = 0;
        int limit = 9;
        if (tight) {
            limit = s[ind] - '0';
        }
        for (int i = 0; i <= limit; i++) {
            int ntight = tight && (i == limit);
            int nstarted = started || (i != 0);
            if (nstarted && i == d) {
                continue;
            }
            ans += f(ind + 1, ntight, nstarted, s, d);
        }
        return dp[ind][tight][started] = ans;
    }
public:
    int countWithout(int n, int d) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return f(0, 1, 0, s, d) - 1;
    }
};
