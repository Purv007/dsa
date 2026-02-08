class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(auto i:nums) sum+=i;
        int res=0;
        for(int i=0;i<n-1;i++){
            sum-=nums[i];
            if(nums[i]>(sum/(double)(n-i-1))) res++;
        }

        return res;
    }
};
