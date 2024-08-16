class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini1=arrays[0][0],maxi1=arrays[0][arrays[0].size()-1];
        int res=0;
        for(int i=1;i<arrays.size();i++){
            int n=arrays[i].size()-1;
            res=max(res,max(abs(mini1-arrays[i][n]),abs(maxi1-arrays[i][0])));
            mini1=min(mini1,arrays[i][0]);
            maxi1=max(maxi1,arrays[i][n]);
        }
        return res;
    }
};
