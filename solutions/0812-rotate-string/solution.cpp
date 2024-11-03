class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        while(n--){
            string st=s.substr(1)+s[0];
            if(st==goal) return true;
            s=st;
        } 
        return false;
    }
};
