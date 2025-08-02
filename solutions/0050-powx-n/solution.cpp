class Solution {
public:
    double myPow(double x, int n) {
        long long m=n;
        if(m<0){
            x=1/x;
            m=-m;
        }
        double pow=1;

        while(m>0){
            if(m %2==1){
                pow*=x;
            }
            x*=x;
            m>>=1;
        }
        return pow;
    }
};
