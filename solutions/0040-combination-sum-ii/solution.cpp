class Solution {
    private:
    void comSum(vector<int>& c, int target,vector<vector<int>>&res,int index,vector<int>&temp){
        if(target<0){
            return;
        }
        if(target==0){
            res.push_back(temp);
        }
        else{
            for(int i=index;i<c.size() && target>=c[i];i++){
                if(i>index && c[i]==c[i-1]){
                    continue;
                }
                temp.push_back(c[i]);
                comSum(c,target-c[i],res,i+1,temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>>res;
        vector<int>temp;
        comSum(c,target,res,0,temp);
        return res;
    }
};
