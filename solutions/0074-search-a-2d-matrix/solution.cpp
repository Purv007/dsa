class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();

        int r=0,c=m-1;
        while(r<n && c>=0){
            int curr=mat[r][c];
            if(curr==target) return true;
            if(target>curr) r++;
            else c--;
        }

        return false;
    }
};
