class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int hcf=numsDivide[0];
        for(int i:numsDivide){
            hcf=gcd(hcf,i);
        }
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i:nums){
            if(hcf%i==0) return res;
            res++;
        }
        return -1;
    }
};
