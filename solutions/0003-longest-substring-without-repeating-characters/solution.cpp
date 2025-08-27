class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1) return n;
        int res=0;
        int l=0,r=1;
        unordered_map<char,int>index;
        index[s[0]]=0;
        while(l<r && r<s.size()){
            char c=s[r];
            if(index.count(c) && index[c]>=l){
                res=max(res,r-l);
                l=index[c]+1;
            }
            index[c]=r;
            r++;
        }
        res=max(res,r-l);
        return res;
    }
};
