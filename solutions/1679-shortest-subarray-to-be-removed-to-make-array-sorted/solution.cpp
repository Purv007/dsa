class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums){
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        if(temp==nums) return 0;

        int left=0,right=nums.size()-1;
        while(right>0 && nums[right-1]<=nums[right]){
            right--;
        }
        int res=right;
        cout<<right<<endl;

        while(left<right && (left==0 || nums[left-1]<=nums[left])){
            while(right<nums.size() && nums[left]>nums[right]){
                right++;
            }
            cout<<left<<" "<<right<<endl;
            res=min(res,right-left-1);
            left++;
        }
        return res;
    }   
};
