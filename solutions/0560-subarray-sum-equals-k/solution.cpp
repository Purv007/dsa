class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        unordered_map<int,int>m;
        int pre=0;
        m[0]++;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            if(m.find(pre-k)!=m.end()){
                res+=m[pre-k];
            }
            m[pre]++;
        }
        return res;
    }
};
