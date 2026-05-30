class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD=1e9+7;
        vector<vector<pair<int,int>>>adj(n);

        for(auto &i:roads){
            adj[i[0]].emplace_back(i[1],i[2]);
            adj[i[1]].emplace_back(i[0],i[2]);
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>q;
        vector<long long>time(n,LLONG_MAX);
        vector<int>paths(n,0);
        time[0]=0;
        paths[0]=1;
        q.emplace(0,0);

        while(!q.empty()){
            long long currtime=q.top().first;
            int node=q.top().second;
            q.pop();

            if(currtime>time[node]) continue;

            for(auto& [neigh,t]:adj[node]){
                if(currtime+t<time[neigh]){
                    time[neigh]=currtime+t;
                    paths[neigh]=paths[node];
                    q.emplace(time[neigh],neigh);
                }
                else if(currtime+t==time[neigh]){
                    paths[neigh]=(paths[neigh]+paths[node])%MOD;
                }
            }
        }
        return paths[n-1];
    }
};
