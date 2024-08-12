class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        if(countIslands(grid) !=1) return 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(countIslands(grid) !=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
private:
    int countIslands(vector<vector<int>>& grid){
        int rows=grid.size();
        int cols=grid[0].size();
        
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        int islands=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    bfs(grid,visited,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int x,int y){
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        q.push({x,y});
        visited[x][y]=true;

        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            auto[curX,curY]=q.front();
            q.pop();

            for(auto[dx,dy]:dir){
                int newX=curX+dx;
                int newY=curY+dy;

                if(newX>=0 && newX<rows && newY>=0 && newY<cols && grid[newX][newY]==1 &&
                !visited[newX][newY]){
                    visited[newX][newY]=true;
                    q.push({newX,newY});
                }
            }
        }
    }
};
