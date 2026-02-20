class Solution {
public:
vector<vector<int>>dp;
    int solve(int e,int f){
        if(e==1 || f==1)return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mn=f;
        int l=1,h=f,temp=0;

        while(l<=h){
            int mid=l+(h-l)/2;
            int left=solve(e-1,mid-1);
            int right=solve(e,f-mid);
            temp=1+max(left,right);
            if(left<right){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            mn=min(mn,temp);
        }

        return dp[e][f]=mn;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,-1));
        return solve(k,n);
    }
};
