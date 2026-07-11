class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        const int LOG = 18;

        // Step 1: Sort values while remembering original indices
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // Step 2: original index -> position in sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // jump[i][k] = position after 2^k jumps
        vector<vector<int>> jump(n, vector<int>(LOG));

        // Step 3: Find the farthest position reachable in one jump
        int right = 0;

        for (int left = 0; left < n; left++) {

            while (right + 1 < n &&
                   arr[right + 1].first - arr[left].first <= maxDiff) {

                right++;
            }

            jump[left][0] = right;

            if (right == left)
                right++;
        }

        // Step 4: Build binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;

        // Step 5: Answer every query
        for (auto &q : queries) {

            int start = pos[q[0]];
            int end = pos[q[1]];

            if (start > end)
                swap(start, end);

            if (start == end) {
                ans.push_back(0);
                continue;
            }

            int curr = start;
            int jumps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (jump[curr][k] < end) {
                    curr = jump[curr][k];
                    jumps += (1 << k);
                }
            }

            if (jump[curr][0] >= end)
                ans.push_back(jumps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
