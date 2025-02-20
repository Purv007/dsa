class Solution {
public:
    bool valid(int num,int target){
        if(target<0 || num<target) return false;
        
        if(num==target) return true;

        return valid(num/10,target-num%10) || valid(num/100,target-num%100) || valid(num/1000,target-num%1000) ; 
    }
    int punishmentNumber(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            if(valid(sq,i)){
                res+=(sq);
            }
        }
        return res;
    }
};
