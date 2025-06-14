class Solution {
public:
    int count(vector<int>& nums,int val){
        int idx=0;
        int res=0;

        while(idx<nums.size()-1){
            if(nums[idx+1]-nums[idx]<=val){
                idx++;
                res++;
            }
            idx++;
        }
        return res;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int mid=l + (r-l)/2;
            if(count(nums,mid)>=p){
                r=mid;
            }else{
                l=mid+1;
            }
        }

        return l;
    }
};
