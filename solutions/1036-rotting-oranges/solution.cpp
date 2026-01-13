class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        queue<pair<int,int>>q;
        int one=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){ 
                    one++;
                }
                else if(g[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int res=0;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(!q.empty() && one){
            int size=q.size();

            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && g[nx][ny]==1){
                        g[nx][ny]=2;
                        one--;
                        q.push({nx,ny});
                    }
                }
            }
            res++;
        }
        return one==0?res:-1;
    }
};
