class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int k=rolls.size()+n;
        int sum=0;
        for(auto i:rolls){
            sum+=i;
        }
        int rem_sum=(mean*k)-sum;
        cout<<rem_sum;

        if(((6*n)<rem_sum) || rem_sum<n ) return {};
        
        int count=rem_sum/n;
        rem_sum-=count*n;
        vector<int>res(n,count);
        int mod=rem_sum%n;
        for(int i=0;i<mod;i++){
            res[i]++;
        }
        return res;

    }
};
