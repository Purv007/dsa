class Solution {
public:
int dup,missing;
    vector<int> findErrorNums(vector<int>& nums) {
        for (int i=1;i<=nums.size();i++){
            int counter=0;
            for (int j=0;j<nums.size();j++){
                if(nums[j]==i)
                {
                    counter++;
                }
            }
            if (counter==2){
                dup=i;
            }
            else if (counter==0){
                missing=i;
            }
            
        }
        return {dup,missing};
    }
};
