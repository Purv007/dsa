class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>count;
        for(auto c:s){
            count[c]++;
        }

        int res=0;
        for(auto [a,b]:count){
            if(b%2==0) res+=2;
            else{
                res+=1;
            }
        }
        return res;
    }
};
