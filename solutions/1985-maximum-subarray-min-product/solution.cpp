class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        // Prefix sum
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            long long curr = (i < n) ? nums[i] : 0;

            while (!st.empty() && nums[st.top()] > curr) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? 0 : st.top() + 1;
                int right = i - 1;

                long long sum = pre[right + 1] - pre[left];
                ans = max(ans, sum * nums[mid]);
            }

            st.push(i);
        }

        return ans % MOD;
    }
};

