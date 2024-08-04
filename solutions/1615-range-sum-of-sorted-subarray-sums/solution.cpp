class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> newNums;
        int i=0,j=0,sum=0;
        while(i<n-1){
            if(j==n){
                i++;
                j=i;
                sum=nums[i];
                newNums.push_back(sum);
                j++;
            }else{
            sum+=nums[j];
            newNums.push_back(sum);
            j++;}
        }
        sort(newNums.begin(),newNums.end());
        long long res=0;
        for(int i=left-1;i<right;i++){
            res+=newNums[i];
        }
        int mod=1e9+7;
        int ret=res%mod;
        return ret;
    }
};
