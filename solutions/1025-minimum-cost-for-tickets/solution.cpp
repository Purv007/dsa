class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INT_MAX) continue;

            int j = i;
            while (j < n && days[j] < days[i] + 1) j++;
            dp[j] = min(dp[j], dp[i] + costs[0]);

            j = i;
            while (j < n && days[j] < days[i] + 7) j++;
            dp[j] = min(dp[j], dp[i] + costs[1]);

            j = i;
            while (j < n && days[j] < days[i] + 30) j++;
            dp[j] = min(dp[j], dp[i] + costs[2]);
        }

        return dp[n];
    }
};
