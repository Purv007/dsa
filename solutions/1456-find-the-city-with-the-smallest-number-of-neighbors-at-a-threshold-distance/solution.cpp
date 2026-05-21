class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {

        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Build graph
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // Run SPFA from every node
        for(int i=0;i<n;i++){
            spfa(n, adj, dist[i], i);
        }

        return func(n, dist, threshold);
    }

    void spfa(
        int n,
        vector<vector<pair<int,int>>>& adj,
        vector<int>& dist,
        int source
    ){

        queue<int> q;

        dist[source] = 0;
        q.push(source);

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto &i : adj[node]){

                int nn = i.first;
                int w = i.second;

                if(dist[node] != INT_MAX &&
                   dist[node] + w < dist[nn]){

                    dist[nn] = dist[node] + w;
                    q.push(nn);
                }
            }
        }
    }

    int func(int n, vector<vector<int>>& d, int l){

        int city = -1;
        int count = n;

        for(int i=0;i<n;i++){

            int reachable = 0;

            for(int j=0;j<n;j++){

                if(i == j) continue;

                if(d[i][j] <= l){
                    reachable++;
                }
            }

            if(reachable <= count){
                count = reachable;
                city = i;
            }
        }

        return city;
    }
};
