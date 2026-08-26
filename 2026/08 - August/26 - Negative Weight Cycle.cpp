class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<int> dist(V, 0);
        for (int i = 1; i <= V; i++) {
            for (auto& e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (i == V) {
                        return true;
                    }
                }
            } 
        }
        return false;
    }
};
