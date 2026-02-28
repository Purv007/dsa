class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int,vector<int>,greater<int>>q;
        int k= m>n?m:n;
        int a=0,b=0;
        for(int i=0;i<k;i++){
            if(a<m){
                q.push(nums1[a++]);
            }
            if(b<n){
                q.push(nums2[b++]);
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.top()); q.pop();
        }
        nums1=res;
    }
};
