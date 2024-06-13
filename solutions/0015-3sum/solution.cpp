class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                int total=nums[i]+nums[j]+nums[k];
                if(total>0){
                    k--;
                }
                else if(total<0){
                    j++;
                }
                else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;

                    while(nums[j]==nums[j-1] && j<k){
                        j++;
                    }
                }
            }
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>>res;
        
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     if((nums[i]+nums[j]+nums[k]==0) && (i!=j) && (i!=k) && (j!=k)){
//                         res.push_back({nums[i],nums[j],nums[k]});
//                     }
//                 }
//             }
//         }
//         bool flag;
//         int m=res.size();
//         for(int i=0;i<m;i++){
//             flag=false;
//             for(int j=i+1;j<m;j++){
//                 if((res[i][0]==res[j][0]) && (res[i][1]==res[j][1]) && (res[i][2]==res[j][3])){
//                     flag=true;
//                 }
//             }
//                 if(flag){
//                     res.erase(res.begin()+2,res.begin()+3);
//                     m--;
//                 }
//         }
        
//         return res;
//     }
// };

