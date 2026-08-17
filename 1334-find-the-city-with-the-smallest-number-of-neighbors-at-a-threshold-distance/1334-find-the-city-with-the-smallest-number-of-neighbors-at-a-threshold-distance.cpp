class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>>dij(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++) dij[i][i]=0;

        for(auto& i:edges){
            int a=i[0];
            int b=i[1];
            adj[a].emplace_back(b,i[2]);
            adj[b].emplace_back(a,i[2]);
        }

        for(int i=0;i<n;i++){
            dijs(n,adj,dij[i],i);
        }

        return func(n,dij,distanceThreshold);
    }

    void dijs(int n,vector<vector<pair<int,int>>>&adj,vector<int>&dist,int s){
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>q;

        q.push({0,s});
        dist[s]=0;

        while(!q.empty()){
            auto [dis,node]=q.top();
            q.pop();

            if(dis>dist[node]) continue;

            for(auto &i:adj[node]){
                int nn=i.first;
                int w=i.second;

                if(dist[nn]>dis+w){
                    dist[nn]=dis+w;
                    q.push({dist[nn],nn});
                }
            }
        }
    }

    int func(int n,vector<vector<int>>&d,int l){
        int city=-1;
        int count=n;

        for(int i=0;i<n;i++){
            int reachable=0;

            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(d[i][j]<=l) reachable++;
            }

            if(reachable<=count){
                count=reachable;
                city=i;
            }
        }
        return city;
    }
};