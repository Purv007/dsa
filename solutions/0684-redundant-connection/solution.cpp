class Solution {
public:
    bool isConnected(int src, int target, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == target) return true;

            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            if (isConnected(u, v, adj)) {
                return e;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
