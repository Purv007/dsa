class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set1 = __builtin_popcount(num1);
        int set2 = __builtin_popcount(num2);
        int rem=abs(set1-set2);
        int temp=1;
        if(set1<set2)
        {
            while(rem>0){
                if((num1 & temp) == 0){//unset bit
                    num1=num1 | temp;
                    rem--;
                }
                temp<<=1;
            }
            return num1;  
        } 
        for(int i=0;i<rem;i++){
            num1=num1 & (num1-1);
        }
        return num1;
    }
};
