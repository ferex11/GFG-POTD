// Recursion
class Solution {
private:
    int n;
    int f(int ind, bool prev, vector<int>& h, vector<int>& l) {
        if (ind == n) {
            return 0;
        }
        int skip = f(ind + 1, prev, h, l);
        int low = l[ind] + f(ind + 1, true, h, l);
        int high = 0;
        if (!prev) {
            high = h[ind] + f(ind + 1, true, h, l);
        }
        return max({skip, low, high});
    }
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        n = h.size();
        return f(0, false,  h, l);
    }
};

// Memoization
class Solution {
private:
    int n;
    int dp[100006][2];
    int f(int ind, bool prev, vector<int>& h, vector<int>& l) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][prev] != -1) {
            return dp[ind][prev];
        }
        int skip = f(ind + 1, false, h, l);
        int low = l[ind] + f(ind + 1, true, h, l);
        int high = 0;
        if (!prev) {
            high = h[ind] + f(ind + 1, true, h, l);
        }
        return dp[ind][prev] = max({skip, low, high});
    }
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        memset(dp, -1, sizeof(dp));
        n = h.size();
        return f(0, false,  h, l);
    }
};

// Tabulation
class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = 1; prev >= 0; prev--) {
                int skip = dp[i + 1][0];
                int low = l[i] + dp[i + 1][1];
                int high = 0;
                if (!prev) {
                    high = h[i] + dp[i + 1][1];
                }
                dp[i][prev] = max({skip, low, high});
            }
        }
        return dp[0][0];
    }
};

// Space Optimization
class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        vector<int> next(2, 0), cur(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = 1; prev >= 0; prev--) {
                int skip = next[0];
                int low = l[i] + next[1];
                int high = 0;
                if (!prev) {
                    high = h[i] + next[1];
                }
                cur[prev] = max({skip, low, high});
            }
            next = cur;
        }
        return next[0];
    }
};
