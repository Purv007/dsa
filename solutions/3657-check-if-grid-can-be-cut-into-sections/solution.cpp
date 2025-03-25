class Solution {
public:
    bool cuts(vector<vector<int>>x,int n){
        sort(x.begin(), x.end(),
             [n](vector<int>& a, vector<int>& b) { return a[n] < b[n]; });
        int gap=0;
        int prev_end=x[0][n+2];
        for(auto i:x){
            if(prev_end<=i[n]){
                gap++;
            }
            prev_end=max(prev_end,i[n+2]);
            if(gap>1) return true;
        }
        return false;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        return cuts(rectangles,0) || cuts(rectangles,1);
    }
};
