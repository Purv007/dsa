class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;

        if(sum%2!=0) return false;
        int total=sum/2;
        vector<vector<int>>dp(nums.size()+1,(vector<int>(total+1,-1)));

        //initialize
        for(int i=0;i<n+1;i++) dp[i][0]=1;
        for(int i=0;i<total+1;i++) dp[0][i]=0;

        //bottom up-approach
        for(int i=1;i<n+1;i++){
            for(int j=1;j<total+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]= dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[n][total];
    }
};
