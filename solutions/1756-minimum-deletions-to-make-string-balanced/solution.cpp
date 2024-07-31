class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int b_count = 0;
        int res=0;

        // dp[i]: The number of deletions required to
        // balance the substring s[0, i)
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                b_count++;
            } else {
                // Two cases: remove 'a' or keep 'a'
                res=min(res+1,b_count);
            }
        }

        return res;
    }
};
