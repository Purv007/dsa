class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int res=0;
        for(auto i:nums){
            while(i>0){
                if(i%10==digit) res++;
                i/=10;
            }
        }
        return res;
    }
};
