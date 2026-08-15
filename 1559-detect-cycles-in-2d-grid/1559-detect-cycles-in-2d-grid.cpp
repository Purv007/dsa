class Solution {
public:
int n,m;
vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int i,int j,int pi,int pj,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        char val=grid[i][j];

        for(auto [dx,dy]:dir){
            int x=i+dx;
            int y=j+dy;

            if(x<0 || y<0 || x>=n || y>=m) continue;

            if(grid[x][y]!=val) continue;

            if(!vis[x][y]){
                if(dfs(x,y,i,j,grid,vis)) return true;
            }
            else if(x!=pi || y!=pj) return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        this->n=grid.size();
        this->m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && dfs(i,j,-1,-1,grid,vis)){
                    return true;
                }
            }
        }

        return false;
    }
};