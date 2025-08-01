class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int count=0;
//moore voting algo
        for(auto i:nums){
            if(count==0){
                curr=i;
            }
            if(i==curr){
                count++;
            }else count--;
        }
        return curr;
    }
};
