class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1;
        int n=nums.size();
        int res=1;

        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                inc++;
                dec=1;
            }
            else if(nums[i+1]<nums[i]){
                inc=1;
                dec++;
            }
            else{
                inc=1;
                dec=1;
            }
            res=max(res,max(inc,dec));
        }
        return res;
    }
};
