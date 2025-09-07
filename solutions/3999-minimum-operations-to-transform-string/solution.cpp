class Solution {
public:
    int minOperations(string s) {
        int first=30;

        for(auto i:s){
            if(i=='a') continue;
            int curr=i-'a';
            first=min(first,curr);
        }

        if(first==30) return 0;

        return 26-first;
    }
};
