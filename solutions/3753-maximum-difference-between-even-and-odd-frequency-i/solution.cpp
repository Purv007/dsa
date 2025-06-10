class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>c;

        for(auto i:s){
            c[i]++;
        }
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(const auto [i,j]:c){
            if(j%2==1){
                maxi=max(maxi,j);
            }
            else{
                mini=min(mini,j);
            }
        }
        return maxi-mini;
    }
};
