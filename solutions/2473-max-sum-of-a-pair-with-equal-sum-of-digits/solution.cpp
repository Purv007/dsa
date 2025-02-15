class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<priority_queue<int, vector<int>, greater<int>>>count(82);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            int t=nums[i];
            while(t>0){
                sum+=t%10;
                t/=10;
            }
            count[sum].push(nums[i]);
            if(count[sum].size()>2){
                count[sum].pop();
            }
        }

        int res=-1;

        for(auto i:count){
            if(i.size()==2){
                int top=i.top();
                i.pop();
                int top2=i.top();
                res=max(res,top+top2);
            }
        }
        return res;
    }
};
