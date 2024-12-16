class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k--){
            auto [val,idx]=pq.top();
            pq.pop();

            int new_val=val*multiplier;
            nums[idx]*=multiplier;
            pq.push({new_val,idx});
        }

        return nums;
    }
};
