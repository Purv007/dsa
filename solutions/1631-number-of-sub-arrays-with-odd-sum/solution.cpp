class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int prefixSum=0;
        int odd=0,even=1;
        int res=0;
        int div=1e9+7;

        for(auto i:arr){
            prefixSum+=i;
            if(prefixSum%2==1){
                odd++;
                res+=even;
            }
            else{
                even++;
                res+=odd;
            }
            res%=div;
        }
        return res;
    }
};
