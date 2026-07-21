class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n=s.size();
        int i=0;
        while(i<n){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            string temp;
            while(i<n && isalnum(s[i])){
                temp+=s[i];
                i++;
            }
            res=temp+" "+res;
        }
        return res.substr(0,res.size()-1);
    }
};
