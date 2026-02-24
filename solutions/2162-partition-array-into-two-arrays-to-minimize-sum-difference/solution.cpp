class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<vector<int>> leftSide = calculateSubsetSum(0, n - 1, nums, n);
        vector<vector<int>> rightSide = calculateSubsetSum(n, 2 * n - 1, nums, n);

        int totalSum = 0;
        for (int x : nums) totalSum += x;

        int halfSum = totalSum / 2;
        int res = INT_MAX;

        for (int i = 0; i <= n; i++) {
            for (int S1 : leftSide[i]) {
                int target = halfSum - S1;

                int S2 = binary(rightSide[n - i], target);

                int sum = S1 + S2;
                res = min(res, abs(2 * sum - totalSum));
            }
        }

        return res;
    }

private:
    vector<vector<int>> calculateSubsetSum(int left, int right, vector<int>& nums, int n) {
        vector<vector<int>> res(n + 1);

        int len = right - left + 1;
        int total = 1 << len;

        for (int mask = 0; mask < total; mask++) {
            int sum = 0;
            int bits = 0;

            for (int j = 0; j < len; j++) {
                if (mask & (1 << j)) {
                    sum += nums[left + j];
                    bits++;
                }
            }

            res[bits].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(res[i].begin(), res[i].end());

        return res;
    }

    int binary(const vector<int>& arr, int target) {
        int up = binaryUp(arr, target);
        int down = binaryDown(arr, target);

        if (up == INT_MAX) return down;
        if (down == INT_MAX) return up;

        return abs(target - up) > abs(target - down) ? down : up;
    }

    int binaryUp(const vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        int ans = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] >= target) {
                ans = arr[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int binaryDown(const vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        int ans = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= target) {
                ans = arr[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
/*
            Problem Statement:
            -----------------
            We are given an array of length 2n (where n ∈ [1, 15]).
            Each number in the array lies within the range [-1e7, 1e7].

            What we need to do:
            -------------------
            - Split the array into two partitions of equal size (n elements each).
            - Our goal is to minimize the difference between the sums of the two partitions.
            - In mathematical terms, we want to minimize:
                    | sum(partition1) - sum(partition2) |

            Initial Thoughts (Brute Force):
            -------------------------------
            - One naive approach is to directly try every possible way of choosing n elements out of 2n.
            - That means we would need to evaluate 2nCn subsets.
            - Example: If n = 15, then we must compute 30C15 ≈ 155 million (~10^8) possibilities.
            - Clearly, this number is far too large to handle within reasonable time constraints.
            - Hence, brute force is NOT possible here.

            Key Observations:
            -----------------
            1. The total sum of all elements is fixed.
            So, if we know the sum of one chosen partition, the other partition's sum is automatically determined.
            This means we don’t need to explicitly compute both partitions separately.

            2. What we are really minimizing is:
                    | totalSum - 2 * chosenSubsetSum |
            Because if one subset has sum = chosenSubsetSum,
            then the other subset’s sum = totalSum - chosenSubsetSum.

            3. This leads us to the idea that we only need to focus on finding a subset sum that is
            as close as possible to totalSum / 2.

            Refined Approach: Meet-in-the-Middle
            ------------------------------------
            - Since n ≤ 15, we can split the array into two halves of size n each.
            - Each half has at most 2^15 = 32768 subsets → small enough to enumerate exhaustively.
            - For each half:
                → Generate all possible subset sums.
                → Additionally, group them according to the number of elements chosen
                (because finally we must choose exactly n elements in total).

            - After this preprocessing, we proceed as follows:
                1. For each possible count of elements chosen from the left half (say k),
                we must complement it with (n - k) elements chosen from the right half.
                2. For every subset sum S1 from the left half with k elements,
                look into the right half's subset sums of size (n - k).
                3. Our target is to find the S2 such that (S1 + S2) is as close as possible to totalSum / 2.
                Because this minimizes the final difference.

            - To achieve this efficiently, we sort the subset sums of each group from the right half.
            - Then, for each S1 from the left, we perform binary search on the right group's sorted sums
            to find the closest S2.
            - With this, we can calculate:
                    | totalSum - 2 * (S1 + S2) |
            and keep track of the global minimum.

            Complexity Analysis:
            --------------------
            Subset Generation:
                - Each half has 2^(n/2) subsets, and for each subset we may process up to n elements.
                - This gives O(n * 2^(n/2)) time.

            Sorting:
                - We sort each group of subset sums.
                - Sorting all groups together is bounded by O(2^(n/2) * log(2^(n/2))) ≈ O(2^(n/2) * n).

            Binary Search:
                - For every subset sum on the left (≈ 2^(n/2)), we perform binary search on the right sums.
                - This gives O(2^(n/2) * log(2^(n/2))).

            Overall Time Complexity:
                - O(n * 2^(n/2)) + O(2^(n/2) * log(2^(n/2)))
                - For n = 15, this is well within computational limits.

            Space Complexity:
            -----------------
            - Each half stores up to 2^(n/2) subset sums.
            - Thus, total space = O(2^(n/2)), which is feasible.
        */
