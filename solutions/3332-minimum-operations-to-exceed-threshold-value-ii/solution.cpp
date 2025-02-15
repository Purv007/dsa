class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>count(nums.begin(),nums.end());
        int res=0;
        // for(int i=0;i<nums.size();i++){
        //     cout<<count.top()<<" ";
        //     count.pop();
        // }
        // for(auto i:nums){
        //     count.push(i);
        // }

        while(count.top()<k && count.size()){
            res++;
            long long small=count.top();
            count.pop();
            long long big=count.top();
            count.pop();
            count.push((2*small)+big);
        }
        return res;
    }
};
