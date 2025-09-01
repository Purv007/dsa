class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n=nums.size();
        int l=0;
        int r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==tar) return mid;

            if(nums[l]<=nums[mid]){//left sorted array
                if(nums[l]<=tar && tar<=nums[mid]){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            else{//right sorted
                if(nums[mid]<=tar && tar<=nums[r]){
                    l=mid+1;
                }
                else{
                    r=mid;
                }

            }
        }
        return -1;
    }
};
