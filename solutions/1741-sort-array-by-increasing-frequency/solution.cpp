class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
       map<int,int>count;
       for(auto i: nums){
        count[i]++;
       } 
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(count[a]==count[b]){
                return a>b;
            }
            return count[a]<count[b];
        });
        return nums;
    }
};
