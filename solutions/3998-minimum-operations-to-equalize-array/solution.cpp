class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flag=true;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(flag && nums[i]!=nums[i+1]){
                flag=false;
            }
        }

        return flag?0:1;
    }
};
