class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i>j) continue;
                int mn=INT_MAX;
                for(int k=i;k<=j;k++){
                    mn=min(mn,cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=mn;
            }
        }
        return dp[1][m];
    }
};
