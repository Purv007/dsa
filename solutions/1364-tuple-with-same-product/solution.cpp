class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mulPairs;
        int res=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mulPairs[nums[i]*nums[j]]++;
            }
        }
        
        for(auto [i,j]:mulPairs)
        {
            if(j>1)
                res+=(j*(j-1)/2);   
        }

        return res*8;
    }
};
