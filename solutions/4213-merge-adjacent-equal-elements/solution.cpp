class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>res;

        for(auto i:nums){
            long long curr=i;
            while(res.size()!=0 && res.back()==curr){
                curr+=res.back();
                res.pop_back();
            }
        res.push_back(curr);
        }
        return res;
    }
};
