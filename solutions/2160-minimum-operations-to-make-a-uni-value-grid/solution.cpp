class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for (auto &row : grid) {
            for (auto &val : row) {
                v.push_back(val);
            }
        }

        sort(v.begin(),v.end());
        int res=0;
        int i=v.size()/2;
        for(int j=0;j<v.size();j++){
            if((v[i]%x) != (v[j]%x)) return -1;
            res+=(abs(v[j]-v[i]))/x;
        }
        return res;
    }
};
