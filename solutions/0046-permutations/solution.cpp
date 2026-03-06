class Solution {
public:
    vector<vector<int>>res;
    int n;
    void func(vector<int>& nums,int i){
        if(i==n) {
            res.push_back(nums);
            return;
        }

        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            func(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        this->n=n;
        func(nums,0);
        return res;
    }
};
