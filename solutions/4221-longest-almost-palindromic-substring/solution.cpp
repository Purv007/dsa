class Solution {
public:
    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    bool almost(string &s, int l, int r) {
        int L = l, R = r;

        while (l < r) {
            if (s[l] == s[r]) {
                l++; r--;
            } else {
                return isPal(s, l + 1, r) || isPal(s, l, r - 1);
            }
        }

        return (R - L + 1) >= 2;
    }

    int almostPalindromic(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i + 1 > ans && almost(s, i, j))
                    ans = j - i + 1;
            }
        }
        return ans;
    }
};

