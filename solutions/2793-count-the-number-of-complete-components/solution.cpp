class Solution {
public:
    void dfs(int curr,vector<vector<int>>&adj,unordered_set<int>&vis,int t[2]){
        vis.insert(curr);
        t[0]++;
        t[1]+=adj[curr].size();

        for(int i:adj[curr]){
            if(!vis.count(i)){
                dfs(i,adj,vis,t);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto &i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int res=0;
        unordered_set<int>vis;

        for(int v=0;v<n;v++){
            if(vis.count(v)) continue;
            //{vertices,edges}
            int t[2]={0,0};
            dfs(v,adj,vis,t);

            if(t[0]*(t[0]-1) == t[1]) res++;
        }
        return res;
    }
};
