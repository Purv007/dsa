class Solution {
public:
    bool prime(int n){
        if(n<=1) return false;
        if(n<=3) return true;

        if((n%2==0) || (n%3==0)) return false;

        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0) return false;
        }
        return true;
    }

    int func(int n,bool p){
        if (n <= 2 && p) return 2;

        int candidate = n;

        while (true) {
            if(p){
                if(prime(candidate)){
                    return candidate;
                }
            }
            else{
                if(!prime(candidate)){
                    return candidate;
                }
            }
            candidate++;
        }
    }

    int minOperations(vector<int>& nums) {
        int res=0;
        bool f=true;
        for(int i=0;i<nums.size();i++){
            res+=func(nums[i],f)-nums[i];
            f= !f;
        }
        return res;
    }
};
