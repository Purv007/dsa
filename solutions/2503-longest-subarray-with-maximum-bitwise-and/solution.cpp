class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res=0;
        int max_no=0;
        int count=0;
        for(auto i:nums){
            max_no=max(max_no,i);
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==max_no){
                count++;
            }
            else{
                res=max(res,count);
                count=0;
            }
        }
        res=max(res,count);
        return res;
    }
};
