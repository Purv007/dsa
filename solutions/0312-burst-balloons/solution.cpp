class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mx = 0;

        for (int k = i; k <= j; k++) {
            int l = nums[i-1];
            int r = nums[j+1];

            int temp = l * nums[k] * r
                       + solve(nums, i, k-1)
                       + solve(nums, k+1, j);

            mx = max(mx, temp);
        }

        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        dp.assign(n+1, vector<int>(n+1, -1));

        return solve(nums, 1, n);
    }
};
