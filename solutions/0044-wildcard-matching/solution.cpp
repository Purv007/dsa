class Solution {
public:
vector<vector<int>>dp;
    bool solve(string& s,string& p,int sin,int pin){
        if(sin==s.size() && pin==p.size()) return true;
        if(pin==p.size()) return false;
        if(dp[sin][pin]!=-1) return dp[sin][pin];
        bool res=false;
        if(p[pin]=='*'){
            res|= solve(s,p,sin,pin+1) || (sin<s.size() && solve(s,p,sin+1,pin));
        }
        else if(sin<s.size() && (p[pin]=='?' || s[sin]==p[pin])){
            res|=solve(s,p,sin+1,pin+1);
        }
        return dp[sin][pin]=res;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0);
    }
};
