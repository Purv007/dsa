class Solution {
public:
    void bfs(vector<set<int>>& adj, vector<int>& c,
             int node, int k) {
        if (k < 0)
            return;
        queue<int> q;
        vector<bool> visit(adj.size());
        q.push(node);
        visit[node] = true;
        int count = 1;
        int res = 1;

        while (!q.empty() && count <= k) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int curr = q.front();
                q.pop();

                for (auto neighbor : adj[curr]) {
                    if (!visit[neighbor]) {
                        q.push(neighbor);
                        visit[neighbor] = true;
                        res++;
                    }
                }
            }
            count++;
        }

        c[node] = res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<int> c1(n, 0);
        vector<int> c2(m, 0);
        // vector<bool> visit1(n),visit2(m);
        vector<set<int>> adj1(n), adj2(m);

        for (auto i : edges1) {
            adj1[i[0]].insert(i[1]);
            adj1[i[1]].insert(i[0]);
        }
        for (auto i : edges2) {
            adj2[i[0]].insert(i[1]);
            adj2[i[1]].insert(i[0]);
        }
        for (int i = 0; i < n; i++){
            // vector<bool> visit1(n);
            bfs(adj1, c1, i, k);
        }
        for (int i = 0; i < m; i++){
            // vector<bool>visit2(m);
            bfs(adj2, c2,i, k - 1);
        }

        // if(k==1) return c1;
        int maxi = INT_MIN;
        for (auto i : c2) {
            maxi = max(maxi, i);
        }
        cout << maxi;
        cout << "c1 :";
        for (auto i : c1)
            cout << i << " ";
        for (int i = 0; i < n; i++) {
            if (k == 1) {
                c1[i] += 1;
            } else {
                c1[i] += maxi;
            }
        }
        cout << "c2 :";
        for (auto i : c2)
            cout << i << " ";
        return c1;
    }
};
