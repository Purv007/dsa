class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddNo = 0;
        for(auto val:nums)
            oddNo += val%2 ? 1 : 0;
        vector<int> prefixEven(oddNo,0);
        vector<int> suffixEven(oddNo,0);
        
        int evenSoFar=0, oddIndex=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2) { prefixEven[oddIndex++]=evenSoFar+1; evenSoFar=0; }
            else evenSoFar++;
        }

        evenSoFar=0; oddIndex=oddNo-1;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]%2) { suffixEven[oddIndex--]=evenSoFar+1; evenSoFar=0; }
            else evenSoFar++;
        }

        int ret=0, i=0, j=k-1;
        while(j<oddNo)
            ret += (prefixEven[i++]*suffixEven[j++]);
        
        return ret;
    }
};   
