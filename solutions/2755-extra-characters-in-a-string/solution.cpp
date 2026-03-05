class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        unordered_set<string> d(dictionary.begin(), dictionary.end());
        vector<int>dp(n+1,0);

        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j=0;j<i;j++){
                auto curr=s.substr(j,i-j);
                if(d.count(curr)){
                    dp[i]=min(dp[i],dp[j]);
                }
            }
        }
        return dp[n];
    }
};
