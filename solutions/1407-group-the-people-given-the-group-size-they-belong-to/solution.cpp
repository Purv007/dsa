class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        int n=g.size();
        unordered_map<int,vector<int>>m;
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++){
            m[g[i]].push_back(i);

            if(m[g[i]].size()==g[i]){
                res.push_back(m[g[i]]);
                m[g[i]].clear();
            }
        }

        return res;
    }
};
