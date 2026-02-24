class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int noBuy=0,buy=0;

        for(int i=n-1;i>=0;i--){
            int nb=noBuy,b=buy;
            noBuy=max(-prices[i]+b,nb);
            buy=max(prices[i]+nb,b);
        }

        return noBuy;
    }
};
