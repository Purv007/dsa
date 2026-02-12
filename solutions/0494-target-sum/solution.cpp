class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int t) {
        int n=arr.size();
        int sum=0;
        for(auto i:arr) sum+=i;
        if(abs(t)>sum || (sum+t)%2!=0) return 0;

        int target=(sum+t)/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        for(int i=0;i<n+1;i++){
            dp[i][0]= 1;
        }

        for(int i=1;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};
