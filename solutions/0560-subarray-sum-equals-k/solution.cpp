class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),res=0;
        vector<int>preSum(n+1);
        preSum[0]=0;
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i-1];
        }

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k) res++;
            }
        }
        return res;
    }
};
