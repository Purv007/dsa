class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0);
        int res = 0;

        queue<int> q;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;

            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int t=q.front();
                q.pop();

                for(int v=0;v<n;v++){
                    if(isConnected[t][v] && !vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
            res++;
        }
        return res;
    }
};
