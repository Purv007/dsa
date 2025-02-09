class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long res=0;
        unordered_map<long long,long long>m;
        for(int i=0;i<n;i++){
            m[nums[i]-i]++;
        }

        for(auto [i,j]:m){
            res+=(j*(j-1))/2;
        }
        long long total=(long long)n*(n-1)/2;

        return total-(long long)res;
    }
};
