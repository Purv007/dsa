class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n){
            return time+1;
        }
        int re=time%(n-1);
        int qu=time/(n-1);
        if(qu%2==0){
            return 1+re;
        }
        else{
            return n-re;
        }
    }
};
