class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;

        for(int node=1;node<=n;node++){
            for(int i=1;i<=node;i++){
                dp[node]+=dp[i-1]*dp[node-i];            
            }
        }
        return dp[n];
    }
};
