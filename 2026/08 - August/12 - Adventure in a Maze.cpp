// Recursion
class Solution {
private:
    int n;
    const int mod = (int) 1e9 + 7;
    const int NEG = -1e9;
    pair<int, int> f(int r, int c, vector<vector<int>>& grid) {
        if (r >= n || c >= n) {
            return {0, NEG};
        }
        if (r == n - 1 && c == n - 1) {
            return {1, grid[r][c]};
        }
        pair<int, int> right = {0, NEG};
        pair<int, int> down = {0, NEG};
        if (grid[r][c] == 1 || grid[r][c] == 3) {
            right = f(r, c + 1, grid);
        }
        if (grid[r][c] == 2 || grid[r][c] == 3) {
            down = f(r + 1, c, grid);
        }
        int paths = (right.first + down.first) % mod;
        int mx = NEG;
        if (right.second != NEG) {
            mx = max(mx, right.second);
        }
        if (down.second != NEG) {
            mx = max(mx, down.second);
        }
        if (mx != NEG) {
            mx += grid[r][c];
        }
        return {paths, mx};
    }
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        n = grid.size();
        pair<int, int> p = f(0, 0, grid);
        if (p.first == 0) {
            return {0, 0};
        }
        return {p.first, p.second};
    }
};

// Memoization
class Solution {
private:
    int n;
    const int mod = (int) 1e9 + 7;
    const int NEG = -1e9;
    vector<vector<pair<int, int>>> dp;
    vector<vector<bool>> vis;
    pair<int, int> f(int r, int c, vector<vector<int>>& grid) {
        if (r >= n || c >= n) {
            return {0, NEG};
        }
        if (r == n - 1 && c == n - 1) {
            return {1, grid[r][c]};
        }
        if (vis[r][c]) {
            return dp[r][c];
        }
        vis[r][c] = true;
        pair<int, int> right = {0, NEG};
        pair<int, int> down = {0, NEG};
        if (grid[r][c] == 1 || grid[r][c] == 3) {
            right = f(r, c + 1, grid);
        }
        if (grid[r][c] == 2 || grid[r][c] == 3) {
            down = f(r + 1, c, grid);
        }
        int paths = (right.first + down.first) % mod;
        int mx = NEG;
        if (right.second != NEG) {
            mx = max(mx, right.second);
        }
        if (down.second != NEG) {
            mx = max(mx, down.second);
        }
        if (mx != NEG) {
            mx += grid[r][c];
        }
        return dp[r][c] = {paths, mx};
    }
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        n = grid.size();
        dp.assign(n, vector<pair<int, int>> (n, {0, 0}));
        vis.assign(n, vector<bool> (n, false));
        pair<int, int> p = f(0, 0, grid);
        if (p.first == 0) {
            return {0, 0};
        }
        return {p.first, p.second};
    }
};

// Tabulation
class Solution {
private:
    int n;
    const int mod = (int) 1e9 + 7;
    const int NEG = -1e9;
    vector<vector<pair<int, int>>> dp;
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        n = grid.size();
        dp.assign(n + 1, vector<pair<int, int>> (n + 1, {0, NEG}));
        dp[n - 1][n - 1] = {1, grid[n - 1][n - 1]};
        for (int r = n - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (r == n - 1 && c == n - 1) {
                    continue;
                }
                pair<int, int> right = {0, NEG};
                pair<int, int> down = {0, NEG};
                if (grid[r][c] == 1 || grid[r][c] == 3) {
                    right = dp[r][c + 1];
                }
                if (grid[r][c] == 2 || grid[r][c] == 3) {
                    down = dp[r + 1][c];
                }
                int paths = (right.first + down.first) % mod;
                int mx = NEG;
                if (right.second != NEG) {
                    mx = max(mx, right.second);
                }
                if (down.second != NEG) {
                    mx = max(mx, down.second);
                }
                if (mx != NEG) {
                    mx += grid[r][c];
                }
                dp[r][c] = {paths, mx};
            }
        }
        if (dp[0][0].first == 0) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};

// Space Optimization
class Solution {
private:
    int n;
    const int mod = (int) 1e9 + 7;
    const int NEG = -1e9;
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        n = grid.size();
        vector<pair<int, int>> next (n + 1, {0, NEG});
        next[n - 1] = {1, grid[n - 1][n - 1]};
        for (int r = n - 1; r >= 0; r--) {
            vector<pair<int, int>> cur (n + 1, {0, NEG});
            for (int c = n - 1; c >= 0; c--) {
                if (r == n - 1 && c == n - 1) {
                    cur[c] = {1, grid[r][c]};
                    continue;
                }
                pair<int, int> right = {0, NEG};
                pair<int, int> down = {0, NEG};
                if (grid[r][c] == 1 || grid[r][c] == 3) {
                    right = cur[c + 1];
                }
                if (grid[r][c] == 2 || grid[r][c] == 3) {
                    down = next[c];
                }
                int paths = (right.first + down.first) % mod;
                int mx = NEG;
                if (right.second != NEG) {
                    mx = max(mx, right.second);
                }
                if (down.second != NEG) {
                    mx = max(mx, down.second);
                }
                if (mx != NEG) {
                    mx += grid[r][c];
                }
                cur[c] = {paths, mx};
            }
            next = cur;
        }
        if (next[0].first == 0) {
            return {0, 0};
        }
        return {next[0].first, next[0].second};
    }
};
