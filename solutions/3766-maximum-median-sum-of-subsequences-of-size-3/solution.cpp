class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long n=nums.size();
        long long trip=n/3;
        long long res=0;
        sort(nums.begin(),nums.end());
        for(int i=n-2;i>0 && trip>0;i-=2){
            res+=nums[i];
            trip--;
        }
        return res;
    }
};
