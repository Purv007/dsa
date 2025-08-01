class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int miss,rep;
        int n=grid.size()*grid.size();
        unordered_map<int,bool>m;
        int sum=0;
        for(auto i:grid){
            for(auto j:i){
                if(m[j]){
                    rep=j;
                }else sum+=j;
                m[j]=true;
            }
        }
        cout<<sum;
        int exp_sum=(n*(n+1))/2;
        miss=exp_sum-sum;
        return {rep,miss};
    }
};
