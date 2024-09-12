class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> all;
        for(char c:allowed){
            all.insert(c);
        }
        int res=0;
        for(auto i:words){
            bool in=true;
            for(char c:i){
                if(all.find(c)!=all.end()){
                    continue;
                }
                else{
                    in=false;
                    break;
                }
            }
            if(in) res++;
        }
        return res;
    }
};
