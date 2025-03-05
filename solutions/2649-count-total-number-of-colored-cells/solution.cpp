class Solution {
public:
    long long coloredCells(int n) {
        long long res=0;
        long long rem=0;
        long long  sub=1;
        for(int i=1;i<=n;i++){
            res+=sub;
            if(i==n-1) rem=res;
            sub+=2;
        }
        return res+rem;

    }
};
