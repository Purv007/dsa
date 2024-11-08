class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int xoor=0;

        for(int i=0;i<n;i++){
            xoor^=nums[i];
        }

        vector<int> res;
        int val=(1<<maximumBit)-1;

        for(int i=n-1;i>=0;i--){
            res.push_back(xoor^val);
            xoor^=nums[i];
        }
        return res;
    }
};
