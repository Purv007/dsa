class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> m;
        for (int i = 1; i <= n; ++i) {
            m.push_back(i);
        }
        int curr=0;
        while(m.size()>1){
            int removal = (curr + k - 1) % m.size();
            m.erase(m.begin()+removal);
            curr=removal;
        }
        return m[0];
    }
};
