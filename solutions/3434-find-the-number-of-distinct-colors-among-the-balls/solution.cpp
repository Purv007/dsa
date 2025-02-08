class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int n=q.size();
        vector<int>res(n);
        unordered_map<int,int>colorCount;
        unordered_map<int,int>ballToColor;

        for(int i=0;i<n;i++){
            int ball=q[i][0];
            int color=q[i][1];

            if(ballToColor.find(ball)!=ballToColor.end()){
                int prevColor=ballToColor[ball];
                colorCount[prevColor]--;

                if(colorCount[prevColor]==0){
                    colorCount.erase(prevColor);
                }
            }
            ballToColor[ball]=color;
            colorCount[color]++;
            res[i]=colorCount.size();
        }
        return res;
    }
};
