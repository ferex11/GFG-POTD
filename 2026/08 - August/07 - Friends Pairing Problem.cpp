// Recursion
class Solution {
private:
    int f(int ind) {
        if (ind == 1) {
            return 1;
        }
        if (ind == 2) {
            return 2;
        }
        int single = f(ind - 1);
        int pairs  = (ind - 1) * f(ind - 2);
        return single + pairs;
    }
public:
    int countFriendsPairings(int n) {
        return f(n);
    }
};

// Memoization
class Solution {
private:
    int dp[19];
    int f(int ind) {
        if (ind == 1) {
            return 1;
        }
        if (ind == 2) {
            return 2;
        }
        if (dp[ind] != -1) {
          return dp[ind];
        }
        int single = f(ind - 1);
        int pairs  = (ind - 1) * f(ind - 2);
        return dp[ind] = single + pairs;
    }
public:
    int countFriendsPairings(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};

// Tabulation
class Solution {
public:
    int countFriendsPairings(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int single = dp[i - 1];
            int pairs = (i - 1) * dp[i -2];
            dp[i] = single + pairs;
        }
        return dp[n];
    }
};


// Space Optimization
class Solution {
public:
    int countFriendsPairings(int n) {
        if (n <= 2) {
            return n;
        }
        int prev2 = 1;
        int prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int cur = prev1 + (i - 1) * prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
