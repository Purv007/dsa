class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int res=0;
        if(m%2!=0){
            for(auto i: nums1){
                res^=i;
            }
        }
        if(n%2!=0){
            for(auto i: nums2){
                res^=i;
            }
        }
        return res;
    }
};
