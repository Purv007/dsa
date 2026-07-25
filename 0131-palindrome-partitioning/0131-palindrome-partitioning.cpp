class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<string>>res;
    vector<string>path;

    void solve(string &s,int st){
        if(st==s.size()){
            res.push_back(path);
            return;
        }

        for(int i=st;i<s.size();i++){
            if(dp[st][i]){
                path.push_back(s.substr(st,i-st+1));
                solve(s,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] && (len==2 || dp[i+1][j-1])){
                    dp[i][j]=1;
                }
            }
        }
        
        solve(s,0);
        return res;
    }
};