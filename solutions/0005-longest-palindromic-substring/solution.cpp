class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0,mx=1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] && (len==2 || dp[i+1][j-1])){
                    dp[i][j]=1;
                    if(len>mx){
                        start=i;
                        mx=len;
                    }
                }
            }
        }

        return s.substr(start,mx);
    }
};
