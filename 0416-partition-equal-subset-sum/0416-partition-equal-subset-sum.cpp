class Solution {
public:
    bool knapsack(vector<int>& nums,int target,int n,vector<vector<int>>&dp){
        if(target==0) return true;
        if(n==0) return false;
        if(dp[n][target]!=-1) return dp[n][target];

        if(nums[n-1]<=target){
            return dp[n][target]=knapsack(nums,target-nums[n-1],n-1,dp) ||
            knapsack(nums,target,n-1,dp);
        } 
        else return dp[n][target]=knapsack(nums,target,n-1,dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(nums.size()+1,(vector<int>(sum+1,-1)));

        return knapsack(nums,target,nums.size(),dp);
    }
};