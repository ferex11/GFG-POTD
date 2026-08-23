class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        if (mat[r][c] == '#') {
            return 0;
        }
        const int inf = 1e9;
        vector<vector<int>> dist(n, vector<int> (m, inf));
        deque<pair<int, int>> dq;
        dist[r][c] = 0;
        dq.push_front({r, c});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int d = 0; d < 4; d++) {
                int nx = x + dr[d];
                int ny = y + dc[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }
                if (mat[nx][ny] == '#') {
                    continue;
                }
                int cost = (nx < x);
                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 1) {
                        dq.push_back({nx, ny});
                    } else {
                        dq.push_front({nx, ny});
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j] == inf) {
                    continue;
                }
                int up_moves = dist[i][j];
                int down_moves = up_moves + i - r;
                if (up_moves <= u && down_moves <= d) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
