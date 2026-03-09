class Solution {
public:
int cyclestart=-1;

    void dfs(int src, vector<bool> &visited, vector<int> adj[],
             vector<int> &parent){
                visited[src]=true;

                for(int i:adj[src]){
                    if(!visited[i]){
                        parent[i]=src;
                        dfs(i,visited,adj,parent);
                    }else if(i!=parent[src] && cyclestart==-1){
                        cyclestart=i;
                        parent[i]=src;
                    }
                }
             }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<bool>visited(n,false);
        vector<int>parent(n,-1);

        vector<int>adj[n];
        for(auto i:edges){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }

        dfs(0,visited,adj,parent);

        unordered_map<int,int>cycleNodes;
        int node=cyclestart;
        do{
            cycleNodes[node]=1;
            node=parent[node];
        }while(node!=cyclestart);

        for(int i=n-1;i>=0;i--){
            if(cycleNodes[edges[i][0]-1] && cycleNodes[edges[i][1]-1]) return edges[i];
        }
        return {};
    }
};
