class Solution {
public:
    long long minEnd(int n, int x) {
        int count=n;
        long long res=x;
        while(--count){
            res=(res+1) | x;
        }
        return res;
    }
};
