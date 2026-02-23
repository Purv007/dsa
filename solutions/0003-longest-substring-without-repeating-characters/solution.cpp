class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);   // ASCII characters
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            if (last[c] >= l) {
                l = last[c] + 1;
            }

            last[c] = r;
            res = max(res, r - l + 1);
        }

        return res;
    }
};
