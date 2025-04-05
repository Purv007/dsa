class Solution {
public:
    int func(vector<int>& nums,int index,int currXor){
        if(index==nums.size()) return currXor;

        int we=func(nums,index+1,currXor^nums[index]);
        int woe=func(nums,index+1,currXor);
        return we+woe;
    }
    int subsetXORSum(vector<int>& nums) {
        return func(nums,0,0);
    }
};
