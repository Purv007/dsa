// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n=nums.size(),count=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]%2==0){
//                 nums[i]=0;
//             }
//             else{
//                 nums[i]=1;
//                 count++;
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<)
//         }
//     }
// };
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};
