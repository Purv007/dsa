class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;

        for(auto i:nums){
            m[i]++;
        }

        int n=nums.size();
        vector<vector<int>>v(n+1);
        for(auto &[a,b]:m){
            v[b].push_back(a);
        }
        vector<int>res;
        for(int i=n;i>=0 && res.size()<k;i--){
            for(int x:v[i]){
                res.push_back(x);
                if(res.size()==k) break;
            }
        }
        return res;
    }
};
