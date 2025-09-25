class Solution {
public:
    vector<vector<int>>res;
    void func(vector<int>& candidates, int target,vector<int>&curr,int ind){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(ind>=candidates.size() ||target<0) return;

        curr.push_back(candidates[ind]);
        func(candidates,target-candidates[ind],curr,ind);
        curr.pop_back();
        func(candidates,target,curr,ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        res.clear();
        func(candidates,target,temp,0);
        return res;
    }
};
