class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n=nums.size();
        vector<long long>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }

        stack<int>s;
        long long res=0;

        for(int i=0;i<=n;i++){
            long long curr=(i<n)?nums[i]:0;

            while(!s.empty() && nums[s.top()]>curr){
                int mid=s.top();
                s.pop();
                int l=s.empty()?0:s.top()+1;
                int r=i-1;

                long long temp=pre[r+1]-pre[l];
                res=max(res,temp*nums[mid]);
            }
            s.push(i);
        }
        return res%MOD;
    }
};
