class Solution {
public:
    void solve(vector<vector<char>>& m) {
        int rows=m.size();
        int cols=m[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};

        for(int i=0;i<cols;i++){
            if(m[0][i]=='O'){
                // visited[0][i]=true;
                q.push(make_pair(0,i));
            }
            if(m[rows-1][i]=='O'){
                // visited[rows-1][i]=true;
                q.push(make_pair(rows-1,i));
            }
        }
        for(int i=1;i<rows-1;i++){
            if(m[i][0]=='O'){
                // visited[i][0]=true;
                q.push(make_pair(i,0));
            }
            if(m[i][cols-1]=='O'){
                // visited[i][cols-1]=true;
                q.push(make_pair(i,cols-1));
            }
        }
        bfs(m,q,visited,dir,rows,cols);

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && m[i][j]=='O'){
                    m[i][j]='X';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& m,queue<pair<int,int>>&q,vector<vector<bool>>&visited,vector<pair<int,int>>&dir,int r,int c){

        while(!q.empty()){
            auto l=q.front();
            int a=l.first;
            int s=l.second;
            q.pop();
            visited[a][s]=true;

            for(int i=0;i<4;i++){
                a+=dir[i].first;
                s+=dir[i].second;
                if(a>=0 && a<r && s>=0 && s<c && !visited[a][s] && m[a][s]=='O'){
                    q.push(make_pair(a,s));
                }
                a-=dir[i].first;
                s-=dir[i].second;
            }
        }
    }
};
