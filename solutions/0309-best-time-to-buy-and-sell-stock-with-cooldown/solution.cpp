class Solution {
public:
vector<vector<int>>dp;
    int solve(vector<int>&prices,int buy,int i){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int res=0;
        if(buy==0){
            res=max(-prices[i]+solve(prices,1,i+1),//buy
                solve(prices,0,i+1));//skip
        }    
        else{
            res=max(prices[i]+solve(prices,0,i+2),//sell
            solve(prices,1,i+1));//skip
        }
        return dp[i][buy]=res;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector(2,-1));
        return solve(prices,0,0);
    }
};
