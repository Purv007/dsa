class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(mat[r][c]==0) continue;
                int top=n+m;
                int left=n+m;
                if(r-1>=0) top=mat[r-1][c];
                if(c-1>=0) left=mat[r][c-1];
                mat[r][c]=min(top,left)+1;
            }
        }
        
        for (int r = n - 1; r >= 0; r--) {
            for (int c = m - 1; c >= 0; c--) {
                if (mat[r][c] == 0) continue;
                int bottom = n+m, right = n+m;
                if (r + 1 < n) bottom = mat[r + 1][c];
                if (c + 1 < m) right = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};
