class Solution {
public:
    bool isConnected(int src,int target,vector<bool>&vis,vector<vector<int>>&adj){
        vis[src]=true;

        if(src==target) return true;

        int found=false;
        for(int i:adj[src]){
            if(!vis[i]){
                found|=isConnected(i,target,vis,adj);
            }
        }
        return found;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<vector<int>>adj(n);
        for(auto i:edges){
            vector<bool>visited(n,false);

            if(isConnected(i[0]-1,i[1]-1,visited,adj)){
                return i;
            }
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        return {};
    }
};