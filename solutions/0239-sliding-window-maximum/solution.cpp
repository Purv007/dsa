class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        deque<int>q;

        for(int i=0;i<n;i++){
            //remove indices not part of curr window
            while(!q.empty() && q.front()<=i-k) q.pop_front();

            // Maintain decreasing order in deque
            while(!q.empty() && nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);

            //push elemetn for curr window
            if(i>=k-1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};
