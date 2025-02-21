class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1);
        int num=n;
        vector<bool>visited(n+1,0);
        func(0,res,visited,n);
        return res;
    }

    bool func(int curr,vector<int>&res,vector<bool>&visited,int n){
        if(curr==res.size()) return true;

        if(res[curr]!=0){
            return func(curr+1,res,visited,n);
        }

        for(int i=n;i>=1;i--){
            if(visited[i]) continue;
            visited[i]=1;
            res[curr]=i;
            if(i==1){
                if(func(curr+1,res,visited,n)) return true;
            }
            else if(curr+i<res.size() && res[curr+i]==0){
                res[curr+i]=i;
                if(func(curr+1,res,visited,n)) return true;

                res[curr+i]=0;
            }
            res[curr]=0;
            visited[i]=false;
        }
        return false;
    }
};
