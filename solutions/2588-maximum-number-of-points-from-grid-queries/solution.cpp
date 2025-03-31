class Solution {
public:

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries){
        int n=grid.size();
        int m=grid[0].size();
        vector<int>res(queries.size());

        vector<pair<int, int>> sortedQueries;
        for (int index = 0; index < queries.size(); index++) {
            sortedQueries.push_back({queries[index], index});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
            q.push({grid[0][0],{0,0}});
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            visited[0][0]=true;
            int count=0;

        for(auto [p,r]:sortedQueries){
            int val=p;
            while(!q.empty() && q.top().first<val){
                auto [a,b]=q.top();
                int x=b.first;
                int y=b.second;
                q.pop();
                count++;

                if((x+1)<n && !visited[x+1][y]){
                    q.push({grid[x+1][y],{x+1,y}});
                    visited[x+1][y]=true;
                }
                if((y+1)<m && !visited[x][y+1]){
                    q.push({grid[x][y+1],{x,y+1}});
                    visited[x][y+1]=true;
                }
                if((x-1)>=0 && !visited[x-1][y]){
                    q.push({grid[x-1][y],{x-1,y}});
                    visited[x-1][y]=true;
                }
                if((y-1)>=0 && !visited[x][y-1]){
                    q.push({grid[x][y-1],{x,y-1}});
                    visited[x][y-1]=true;
                }
            }
            res[r]=count;
        }
        return res;
    }
};

