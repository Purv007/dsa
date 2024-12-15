class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<bool>mark(n,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            pq.emplace(nums[i],i);
        }
        long long res=0;
        while(!pq.empty()){
            auto [mini,idx]=pq.top();
            pq.pop();

            if(mark[idx]) continue;

            res+=mini;
            mark[idx]=true;

            if(idx>0 && !mark[idx-1]){
                mark[idx-1]=true;
            }
            if(idx<n-1 && !mark[idx+1]){
                mark[idx+1]=true;
            }
        }
        return res;
    }
};
