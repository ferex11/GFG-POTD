class Solution {
public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (vector<int>& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (auto& e : adj[u]) {
                int v = e.first;
                indegree[v]++;
            }
        }
        queue<int> q;
        for (int u = 0; u < V; u++) {
            if (indegree[u] == 0) {
                q.push(u);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto& e : adj[u]) {
                int v = e.first;
                int w = e.second;
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;
        for (int u : topo) {
            if (dist[u] != INT_MIN) {
                for (auto& e : adj[u]) {
                    int v = e.first;
                    int w = e.second;
                    dist[v] = max(dist[v], dist[u] + w);
                }
            }
        }
        return dist;
    }
};
