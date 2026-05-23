class Solution {
public:
vector<int> size,parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px==py) return false;
        if(size[px]>size[py]){
            parent[py]=px;
            size[px]+=size[py];
        }
        else{
            parent[px]=py;
            size[py]+=size[px];
        }
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        parent.resize(n*m);
        size.resize(n*m,1);

        for (int i = 0; i < n*m; i++) {
            parent[i]=i;
        }

        int res=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') res++;
            }
        }

        vector<pair<int,int>> dir = {{0,1},{1,0}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0') continue;

                int node=i*m + j;

                for(auto [dx,dy]:dir){
                    int ni = i + dx;
                    int nj = j + dy;

                    if (ni < n && nj < m && grid[ni][nj] == '1') {
                        int adj = ni * m + nj;
                        if (find(node) != find(adj)) {
                            unite(node, adj);
                            res--;
                        }
                    }
                }
            }
        }
        return res;
    }
};
