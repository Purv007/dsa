class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       vector<int> res;
       if(n<0) return res;

       if(n==1){
        res.push_back(0);
        return res;
       }

       vector<int>deg(n);
       vector<vector<int>>adj(n);

       for(auto x:edges){
        int i=x[0];
        int j=x[1];
            deg[i]++;
            deg[j]++;
            adj[i].push_back(j);
            adj[j].push_back(i);
       }
       queue<int>q;
       for(int i=0;i<n;i++){
        if(deg[i]==1){
            q.push(i);
        }
       }

       while(n>2){
        int size=q.size();
        n-=size;

        while(size-->0){
            int top=q.front();
            q.pop();
            for(int i:adj[top]){
                deg[i]--;
                if(deg[i]==1){
                    q.push(i);
                }
            }
        }
       }

       while(!q.empty()){
        int t=q.front();
        q.pop();
        res.push_back(t);
       }

       return res;

    }
};
