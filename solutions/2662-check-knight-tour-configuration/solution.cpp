class Solution {
public:
int n;
    bool func(vector<vector<int>>& grid,int x,int y,int count){
        if(x>=n || x<0 || y<0 || y>=n || grid[x][y]!=count) return false;
        if(count==(n*n-1)) return true;

        return func(grid,x+2,y+1,count+1) || func(grid,x+2,y-1,count+1) || func(grid,x-2,y+1,count+1) || func(grid,x-2,y-1,count+1) || func(grid,x+1,y+2,count+1) || func(grid,x-1,y+2,count+1) || func(grid,x-1,y-2,count+1) || func(grid,x+1,y-2,count+1);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        n=grid.size();
        return func(grid,0,0,0);
    }
};
