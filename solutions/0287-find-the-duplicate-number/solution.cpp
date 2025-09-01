class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int r=n-1;

        while(l<r){
            int mid=l+(r-l)/2;
            int c=0;
            for(auto i:nums){
                if(i<=mid) c++;
            }

            if(c<=mid){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
};
