class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> streak;
        sort(nums.begin(),nums.end());

        for(auto num: nums){
            int root=(int)sqrt(num);
            cout<<root<<endl;

            if(root*root==num && streak.find(root)!=streak.end()){
                streak[num]=streak[root]+1;
            }else{
                streak[num]=1;
            }
        }

        int res=0;
        for(auto [k,len]:streak)
        {
            res=max(res,len);
        }
        return res<2?-1:res;
    }
};
