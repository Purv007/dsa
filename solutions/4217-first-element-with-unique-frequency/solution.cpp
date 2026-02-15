class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }

        unordered_map<int,int> count;
        for(auto &p : m) count[p.second]++;


        for(auto x:nums){
            if(count[m[x]]==1) return x;
        }
        return -1;
    }
};
