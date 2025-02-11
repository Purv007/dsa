class Solution {
public:
    vector<int>kmp(string s) {
        vector<int>lps(s.size(),0);
        for (int i=1; i < lps.size(); i++) {
            int prev_idx = lps[i-1];
            while (prev_idx > 0 &&  s[i]!=s[prev_idx]) {
                prev_idx = lps[prev_idx - 1];
            }
            lps[i]= prev_idx + (s[i]==s[prev_idx] ? 1 :0);
        }
        return lps;
    }
    string removeOccurrences(string s, string part) {
        vector<int>lps=kmp(part);
        string res;
        vector<int>prefixMatches;
        
        for(char c:s){
            res.push_back(c);
            int j=prefixMatches.empty() ? 0 : prefixMatches.back();
            while(j>0 && part[j]!=c){
                j=lps[j-1];
            }
            if(part[j]==c){
                j++;
            }
            prefixMatches.push_back(j);
            if(j==part.size()){
                res.resize(res.size()-part.size());
                prefixMatches.resize(prefixMatches.size()-part.size());
            }
        }
        return res;
    }
};
