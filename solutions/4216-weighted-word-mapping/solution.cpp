class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for(auto i:words){
        int t=0;
            for(auto j:i){
                int c=j-'a';
                t+=weights[c];
            }
            t%=26;
            res+=char('a'+25-t);
        }
        return res;
    }
};
