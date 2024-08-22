class Solution {
public:
    int findComplement(int num) {
        int res=0,index=0;
        if(num==0) return 1;

        while(num){
            int temp=num & 1;
            if(temp==0){
                res+=pow(2,index);
            }
            num=num>>1;
            index++;
        }
        return res;
    }
};
