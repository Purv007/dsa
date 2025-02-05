class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first=0,second=0;
        int diff=0;

        if(s1==s2) return true;
        if(s1.length()!=s2.length()) return false;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diff++;
                if(diff>2) return false;
                else if(diff==1){
                    first=i;
                }
                else{
                    second=i;
                }
            }
        }

        return s1[first]==s2[second] && s1[second]==s2[first];
    }
};
