class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        int cnt=0;
        vector<bool>vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>m;

        m.push({0,0});

        while(cnt<n){
            auto [cost,node]=m.top();
            m.pop();

            if(vis[node]) continue;
            
            vis[node]=true;
            res+=cost;
            cnt++;

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int d=abs(points[i][0]-points[node][0]) + 
                    abs(points[i][1]-points[node][1]);
                    m.push({d,i});
                }
            }
        }
        return res;
    }
};
