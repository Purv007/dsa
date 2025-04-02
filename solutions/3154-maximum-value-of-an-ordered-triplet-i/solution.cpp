class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0,a=0,b=0;
        int n=nums.size();
        for(int k=0;k<n;k++){
            res=max(res,a*nums[k]);
            a=max(a,b-nums[k]);
            b=max(b,(long long)nums[k]);
        }
        return res;
    }
};
