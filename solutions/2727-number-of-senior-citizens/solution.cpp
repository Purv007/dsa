class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(int i=0;i<details.size();i++){
            if(details[i][11]>'6' || (details[i][11]=='6' && details[i][12]>'0')){
                res++;
            }
        }
        return res;
    }
};
