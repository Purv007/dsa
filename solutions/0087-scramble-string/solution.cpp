class Solution {
public:
    int dp[31][31][31]; 

    bool solve(string &a, string &b, int i1, int i2, int len) {

        if (dp[i1][i2][len] != -1)
            return dp[i1][i2][len];

        // if substrings equal
        if (a.substr(i1, len) == b.substr(i2, len))
            return dp[i1][i2][len] = 1;

        if (len == 1)
            return dp[i1][i2][len] = 0;

        for (int k = 1; k < len; k++) {

            // no swap case
            if (solve(a, b, i1, i2, k) &&
                solve(a, b, i1 + k, i2 + k, len - k))
                return dp[i1][i2][len] = 1;

            // swap case
            if (solve(a, b, i1, i2 + len - k, k) &&
                solve(a, b, i1 + k, i2, len - k))
                return dp[i1][i2][len] = 1;
        }

        return dp[i1][i2][len] = 0;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;

        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0, n);
    }
};
