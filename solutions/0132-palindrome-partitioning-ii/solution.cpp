class Solution {
public:
vector<int>t;
int dp[2001][2001];

    int solve(string &s, int i) {
    if (i==s.size()) return -1;
    if (t[i] != -1) return t[i];

    int mn=s.size();
    for(int j=i;j<s.size();j++){
        if(dp[i][j]){
            mn=min(mn,1+solve(s,j+1));
        }
    }

    return t[i] = mn;
}

    int minCut(string s) {
        int n=s.size();
        t.resize(n,-1);
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;

        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && (len==2 || dp[i+1][j-1])){ 
                    dp[i][j] = 1;
                }
            }
        }
        return solve(s,0);
    }
};
