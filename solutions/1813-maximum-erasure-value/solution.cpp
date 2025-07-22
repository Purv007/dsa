class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        int res=0;
        int sum=0;
        int l=0;
        for(int r=0;r<n;r++){
            while(m[nums[r]]>0){
                sum-=nums[l];
                m[nums[l]]--;
                l++;
            }
            sum+=nums[r];
            m[nums[r]]++;
            res=max(res,sum);
        }
        return res;
    }
};
