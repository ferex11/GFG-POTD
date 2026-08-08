class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionSets(int u, int v) {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        if (parent_u == parent_v) {
            return;
        }
        if (size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        } else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};
class Solution {
public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int extra_edges = 0;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                extra_edges++;
            } else {
                ds.unionSets(u, v);
            }
        }
        int cnt_components = 0;
        for (int u = 0; u < n; u++) {
            if (ds.findParent(u) == u) {
                cnt_components++;
            }
        }
        if (extra_edges >= cnt_components - 1) {
            return cnt_components - 1;
        }
        return -1;
    }
};
