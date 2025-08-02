class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=0,res=INT_MIN;

        for(auto i:nums){
            maxi=max(i,maxi+i);
            res=max(res,maxi);
        }
        return res;
    }
};
