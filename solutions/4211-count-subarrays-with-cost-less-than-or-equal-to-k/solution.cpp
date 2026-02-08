class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int>mx,mn;
        long long res=0;
        int l=0;

        for(int r=0;r<nums.size();r++){
            while(!mx.empty() && nums[mx.back()]<=nums[r]) mx.pop_back();
            mx.push_back(r);

            while (!mn.empty() && nums[mn.back()] >= nums[r]) mn.pop_back();
            mn.push_back(r);

            while((long long)(nums[mx.front()]-nums[mn.front()]) * (r-l+1)>k){
                if(mx.front()==l) mx.pop_front();
                if(mn.front()==l) mn.pop_front();
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
};
