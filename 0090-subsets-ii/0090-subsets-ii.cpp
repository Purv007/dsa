class Solution {
public:
vector<vector<int>>res;

    void func(vector<int>&nums,vector<int>&curr,int i){
        if(i==nums.size()){
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        func(nums,curr,i+1);
        curr.pop_back();
        
        int nxt=i+1;
        while(nxt<nums.size() && nums[i]==nums[nxt]) nxt++;
        func(nums,curr,nxt);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>curr;
        // res.push_back(curr);
        func(nums,curr,0);
        return res;
    }
};