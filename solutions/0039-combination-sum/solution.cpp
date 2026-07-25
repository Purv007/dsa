class Solution {
public:
    vector<vector<int>>res;
    void recur(vector<int>&can,int t,vector<int>&curr,int sum,int i){
        if(sum==t){
            res.push_back(curr);
            return;
        }
        if(sum>t || i>=can.size()) return;

        curr.push_back(can[i]);
        recur(can,t,curr,sum+can[i],i);
        curr.pop_back();
        recur(can,t,curr,sum,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        int n=can.size();
        vector<int>temp;
        recur(can,target,temp,0,0);
        return res;
    }
};
