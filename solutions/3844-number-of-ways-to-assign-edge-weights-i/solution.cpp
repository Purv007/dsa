class Solution {
public:
    int res = 0;
    const int MOD = 1e9 + 7;

    void dfs(int node, int par, vector<vector<int>>& adj, int depth) {
        res = max(res, depth);

        for(int child : adj[node]) {
            if(child != par)
                dfs(child, node, adj, depth + 1);
        }
    }

    long long power(long long a, long long b) {
        long long ans = 1;
        while(b) {
            if(b & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj, 0);

        if(res == 0) return 1;

        return power(2, res - 1);
    }
};
