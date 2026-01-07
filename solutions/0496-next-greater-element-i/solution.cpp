class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        stack<int>s;
        unordered_map<int,int>m;
        for(auto i:nums2){
            while(!s.empty() && s.top()<i){
                m[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }

        for(int i:nums1){
            res.push_back(m.count(i) ? m[i] : -1);
        }
        
        return res;
    }
};
