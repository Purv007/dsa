class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total_1=0,n=nums.size();
        if(n==1) return 0;
        for(auto i: nums){
            total_1+= i;
        }

        int count =0;
        for(int i=0;i<total_1;i++){
            count+=nums[i];
        }
        int mx=count;
        int k=total_1;
        for(int i=k;i<k+n;i++){
            count-=nums[(i-k)%n];
            count+=nums[i%n];
            mx=max(mx,count);
        }
        return total_1-mx;
    }
};
