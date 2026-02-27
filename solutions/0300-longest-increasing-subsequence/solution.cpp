// ---------------------Printing LIS-------------------------
// class Solution {
// public:
//     vector<int> getLIS(vector<int>& nums) {
//         int n=nums.size();
//         int res=0;
//         int last_idx=0;
//         vector<int>dp(n,1),hash(n);
//         for(int i=0;i<n;i++){
//             hash[i]=i;
//             for(int prev=0;prev<i;prev++){
//                 if(nums[i]>nums[prev] && dp[i]<1+dp[prev]){
//                     dp[i]=1+dp[prev];
//                     hash[i]=prev;
//                 }
//             }
//             if(res<dp[i]){
//                 res=dp[i];
//                 last_idx=i;
//             }
//         }
        
//         vector<int>lis;
//         lis.push_back(nums[last_idx]);
//         while(hash[last_idx]!=last_idx){
//             last_idx=hash[last_idx];
//             lis.push_back(nums[last_idx]);
//         }
//         reverse(lis.begin(),lis.end());
//         return lis;
//     }
// };
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
