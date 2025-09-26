class Solution {
public:
    vector<vector<int>> res;

    void func(vector<int>& candidates, int target, vector<int>& curr, int ind) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (ind >= candidates.size() || target < 0) return;

        curr.push_back(candidates[ind]);
        func(candidates, target - candidates[ind], curr, ind + 1);
        curr.pop_back();

        int next = ind + 1;
        while (next < candidates.size() && candidates[next] == candidates[ind]) next++;
        func(candidates, target, curr, next);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        res.clear();
        func(candidates, target, temp, 0);
        return res;
    }
};

