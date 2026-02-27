class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n), dec(n);

        // -------- LIS from left --------
        vector<int> tails;
        for(int i = 0; i < n; i++) {
            int pos = lower_bound(tails.begin(), tails.end(), nums[i]) - tails.begin();
            inc[i] = pos + 1;

            if(pos == tails.size())
                tails.push_back(nums[i]);
            else
                tails[pos] = nums[i];
        }

        // -------- LIS from right (for decreasing part) --------
        tails.clear();
        for(int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(tails.begin(), tails.end(), nums[i]) - tails.begin();
            dec[i] = pos + 1;

            if(pos == tails.size())
                tails.push_back(nums[i]);
            else
                tails[pos] = nums[i];
        }

        int maxMountain = 0;

        for(int i = 1; i < n - 1; i++) {
            if(inc[i] > 1 && dec[i] > 1) {
                maxMountain = max(maxMountain, inc[i] + dec[i] - 1);
            }
        }

        return n - maxMountain;
    }
};
