class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor_sum=0;
        for(auto i:derived){
            xor_sum^=i;
        }
        return xor_sum==0;
    }
};
