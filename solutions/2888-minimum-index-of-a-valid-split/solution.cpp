class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int num=nums[0];
        int count=0;
        for(auto i:nums){
            if(i==num) count++;
            else count--;
            if(count==0){
                num=i;
                count=1;
            }
        }
        int freq=0;
        for(int i:nums){
            if(i==num) freq++;
        }
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num) temp++;
            if(((i+1)/2<temp)  && ((freq-temp)>(nums.size()-i-1)/2)) return i;
        }
        return -1;
    }
}; 
