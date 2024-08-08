class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int count=1,dir=0;
        int i=rStart,j=cStart;
        vector<vector<int>>res;
        res.push_back({rStart,cStart});
        int step=1,changeCount=0;
        while(count<rows*cols){
            for(int k=0;k<step;k++){
                if(dir%4==0){
                    j++;
                }
                else if(dir%4==1){
                    i++;
                }
                else if(dir%4==2){
                    j--;
                }
                else if(dir%4==3){
                    i--;
                }
                if(j<cols && i<rows && i>=0 && j>=0){
                    res.push_back({i,j});
                    count++;
                }
            }
            changeCount++;
            if(changeCount==2){
                changeCount=0;
                step++;
            }
            dir++;
        }
        return res;
    }
};

