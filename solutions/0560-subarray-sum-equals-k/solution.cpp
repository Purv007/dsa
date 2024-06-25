// class Solution {
// public:
//     int subarraySum(vector<int>& n, int k) {
//         int l=0,r=0,sum=0,res=0;
//         while(r<n.size()){
//             sum+=n[r];
//             while(sum>k){
//                 if(l+1<n.size())
//                     sum-=n[l++];
//             }
//             if(sum==k){
//                 res++;
//             }
//             if(sum<k){
//                 r++;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    //PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
//PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
    }
};
