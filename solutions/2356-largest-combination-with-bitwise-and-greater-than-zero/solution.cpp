class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0;
        for(int i=0;i<24;i++){
            int size=0;
            for(auto j:candidates){
                if((j & (1<<i))!=0) size++;
            }
            res=max(res,size);
        }
        return res;
    }
};
