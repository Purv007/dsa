class Solution {
public:
    // int ones(int n){
    //     int res=0;
    //     cout<<n<<endl;
    //     while(n>0){
    //         int digit=n%2;
    //         n/=2;
    //         if(digit) res++;
    //     }
    //     return res;
    // }
    bool canSortArray(vector<int>& nums) {
        // vector<int> cpy(nums.begin(),nums.end());
        // sort(cpy.begin(),cpy.end());
        // if(nums==cpy) {
        //     return true;
        // }
        int max_set=__builtin_popcount(nums[0]);
        int max_curr=nums[0];
        int min_curr=nums[0];
        int max_prev=INT_MIN;
        for(int i=1;i<nums.size();i++){
            int curr=__builtin_popcount(nums[i]);
            if(curr==max_set){
                min_curr=min(min_curr,nums[i]);
                max_curr=max(max_curr,nums[i]);
            }
            else{ 
                if(max_prev>min_curr){
                    return false;
                }
                max_prev=max_curr;
                max_set=curr;
                max_curr=nums[i];
                min_curr=nums[i];
            }
        }
        if(max_prev>min_curr){
            return false;
        }
        return true;
    }
};
