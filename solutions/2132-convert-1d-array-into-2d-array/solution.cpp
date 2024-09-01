class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int x=original.size();
        if((m*n)!=x){
            return {};
        }
        if(m==1){
            return {original};
        }
        vector<vector<int>> res(m,vector<int>(n));

        for(int i=0;i<x;i++){
            res[i/n][i%n]=original[i];
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
//         int x = original.size();
//         if (m * n != x) {
//             return {};
//         }
        
//         vector<vector<int>> res(m, vector<int>(n));  // Initialize a 2D vector with m rows and n columns
        
//         for (int i = 0; i < x; i++) {
//             res[i / n][i % n] = original[i];  // Fill the 2D array with values from the original array
//         }
        
//         return res;
//     }
// };

