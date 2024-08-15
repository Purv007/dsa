// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int res=0;
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         vector<int> shortest_dist;
//         int left=0,right=n-1;
//         while(left<right){
//             int mid=(left+right)/2;

//             if(=mid){
//                 return mid;
//             }
//             else if(count<mid){
//                 right=mid-1;
//             }
//             else{
//                 left=mid+1;
//             }
//         }
//     }
// };
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        int maxElement=*max_element(nums.begin(),nums.end());
        vector<int> shortest_dist(maxElement+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(nums[i]-nums[j]);
                shortest_dist[d]++;
            }
        }
        for(int dist=0;dist<=maxElement;dist++){
            k-=shortest_dist[dist];

            if(k<=0){
                return dist;
            }
        }
        return -1;
    }
};
