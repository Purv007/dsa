class Solution {
public:
vector<int>dp;
int func(vector<int>& cost,int n){
    if(n>=cost.size()) return 0;
    if(dp[n]!=-1)return dp[n];
    
    return dp[n]=cost[n]+min(func(cost,n+1),func(cost,n+2));
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n,-1);
        return min(func(cost,0),func(cost,1));
    }
};
