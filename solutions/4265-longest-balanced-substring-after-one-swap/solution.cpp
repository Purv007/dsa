class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int total0 = count(s.begin(), s.end(), '0');
        int total1 = n - total0;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + (s[i] == '1' ? 1 : -1);
        
        // Store all indices for each prefix value
        unordered_map<int, vector<int>> positions;
        unordered_map<int, int> first;
        positions[0].push_back(0);
        first[0] = 0;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int p = pre[i];
            
            // Case 1: no swap
            if (first.count(p))
                ans = max(ans, i - first[p]);
            
            // Case 2: +2 imbalance, need spare '0' outside
            // Need earliest l with pre[l]==p-2 and (i-l-2)/2 < total0
            // i.e. l > i - 2*total0 - 2
            if (positions.count(p - 2)) {
                auto& vec = positions[p - 2];
                int lo = i - 2 * total0 - 2 + 1; // l must be > i-2*total0-2
                // find earliest index in vec that is >= lo
                // but we want EARLIEST (for longest window), so just use first if valid
                // if first[p-2] >= lo, use it; else binary search for earliest >= lo
                int l = first[p - 2]; // earliest
                if (l <= i - 2 * total0 - 2) {
                    // first is too early (window too big), find earliest valid
                    auto it = lower_bound(vec.begin(), vec.end(), lo);
                    if (it != vec.end()) l = *it;
                    else l = -1;
                }
                if (l != -1) {
                    int winLen = i - l;
                    if (winLen % 2 == 0 && total0 > (winLen - 2) / 2)
                        ans = max(ans, winLen);
                }
            }
            
            // Case 3: -2 imbalance, need spare '1' outside
            if (positions.count(p + 2)) {
                auto& vec = positions[p + 2];
                int lo = i - 2 * total1 - 2 + 1;
                int l = first[p + 2];
                if (l <= i - 2 * total1 - 2) {
                    auto it = lower_bound(vec.begin(), vec.end(), lo);
                    if (it != vec.end()) l = *it;
                    else l = -1;
                }
                if (l != -1) {
                    int winLen = i - l;
                    if (winLen % 2 == 0 && total1 > (winLen - 2) / 2)
                        ans = max(ans, winLen);
                }
            }
            
            if (!first.count(p)) first[p] = i;
            positions[p].push_back(i);
        }
        return ans;
    }
};

