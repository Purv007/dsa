class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>deg(n,0);
        vector<vector<int>>adj(n);

        for(auto i:pre){
            int a=i[0];
            int b=i[1];

            deg[a]++;
            adj[b].push_back(a);
        }

        queue<int>q;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(deg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int t=q.front();
            res.push_back(t);
            q.pop();

            for(auto i:adj[t]){
                if(--deg[i]==0){
                    q.push(i);
                }
            }
        }
        return res.size()==n?res:vector<int>();
    }
};
