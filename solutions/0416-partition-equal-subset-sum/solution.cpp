class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;

        if(sum%2==1) return false;
        int t=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(t,-1));
        return func(0,t,0,dp,nums);
    }

    bool func(int idx,int target,int sum,vector<vector<int>>&dp,vector<int>& nums){
        if(target==sum) return true;
        if(idx==nums.size()-1) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        if(nums[idx]+sum>target) return func(idx+1,target,sum,dp,nums);
        int take=func(idx+1,target,sum+nums[idx],dp,nums);
        int leave=func(idx+1,target,sum,dp,nums);
        return dp[idx][sum]=take||leave;
    }
};
