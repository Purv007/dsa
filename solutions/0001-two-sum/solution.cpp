class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        
        vector<int> res;
        map<int, int> mp; // Create a map to store the value-index pairs

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i]; // Current number
            int more = target - first; // The other number needed to reach the target

            if (mp.find(more) != mp.end()) { // If the other number is already in the map
                res.push_back(i); // Add the current index to the result
                res.push_back(mp[more]); // Add the other number's index to the result
                break; // We found a valid pair, so exit the loop
            }
            mp[first] = i; // Add the current number and its index to the map
        }
        return res;
    }
};
