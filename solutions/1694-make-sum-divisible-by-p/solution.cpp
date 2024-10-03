class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long sum = 0;
        int n = nums.size();
        
        // Calculate the total sum of the array
        for (int i : nums) {
            sum += i;
        }
        
        int rem = sum % p;  // Remainder when sum is divided by p
        if (rem == 0) return 0;  // If the sum is already divisible by p, return 0
        
        unordered_map<int, int> prefix;
        prefix[0] = -1;  // To handle cases where the exact prefix is found
        int minLen = n;
        long prefixSum = 0;
        
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int mod = prefixSum % p;
            int target = (mod - rem + p) % p;  // Find the required prefix to make the sum divisible
            
            if (prefix.find(target) != prefix.end()) {
                minLen = min(minLen, i - prefix[target]);
            }
            prefix[mod] = i;  // Store the current prefix modulo p
        }
        
        return (minLen == n) ? -1 : minLen;  // If no valid subarray is found, return -1
    }
};

