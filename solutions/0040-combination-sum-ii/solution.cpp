class Solution {
public:
    vector<vector<int>>res;
    void recur(vector<int>&can,int t,vector<int>&curr,int i){
        if(t==0){
            res.push_back(curr);
            return;
        }
        if(t<0 || i>=can.size()) return;

        curr.push_back(can[i]);
        recur(can,t-can[i],curr,i+1);
        curr.pop_back();

        int nxt=i+1;
        while(nxt<can.size() && can[nxt]==can[i]) nxt++;
        recur(can,t,curr,nxt);
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        int n=can.size();
        vector<int>temp;
        recur(can,target,temp,0);
        return res;
    }
};
