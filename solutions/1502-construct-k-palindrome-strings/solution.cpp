class Solution {
public:
    bool canConstruct(string s, int k) {
        int single=0;
        vector<int>freq(26);
        if(s.length()<k) return false;
        for(char c:s){
            freq[c-'a']++;
        }
        for(auto a:freq){
            single+=a%2;
        }
        if(single>k) return false;

        return 1;
    }
};
