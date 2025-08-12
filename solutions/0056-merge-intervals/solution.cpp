class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        vector<int>t=intervals[0];
        for(int i=1;i<n;i++){
            if(t[1]<intervals[i][0]){
                res.push_back(t);
                t=intervals[i];
            }
            else{
                t[1]=max(t[1],intervals[i][1]);
            }
        }
        res.push_back(t);
        return res;
    }
};
