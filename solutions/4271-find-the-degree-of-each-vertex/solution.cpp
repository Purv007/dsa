class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>res(matrix.size());
        int count=0;
        for(auto i:matrix){
            for(auto x:i){
                if(x==1) res[count]++;
            }
            count++;
        }
        return res;
    }
};
