class Solution {
public:
int n,m;
vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    bool bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{i,j},{-1,-1}});
        vis[i][j]=true;

        while(!q.empty()){
            auto [node,parent]=q.front();
            q.pop();

            auto [i,j]=node;
            char val=grid[i][j];

            for(auto [dx,dy]:dir){
                int x=i+dx;
                int y=j+dy;

                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==val){
                    pair<int,int>nei={x,y};

                    if(!vis[x][y]){
                        vis[x][y]=true;
                        q.push({nei,node});
                    }
                    else if(nei!=parent) return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        this->n=grid.size();
        this->m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && bfs(i,j,grid,vis)){
                    return true;
                }
            }
        }

        return false;
    }
};
