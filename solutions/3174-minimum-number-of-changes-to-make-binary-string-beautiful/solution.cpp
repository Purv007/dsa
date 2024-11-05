class Solution {
public:
    int minChanges(string s) {
        int count;
        int res;
        char c=s[0];

        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                count++;
                continue;
            }

            if(count%2==0){
                count=1;
            }
            else{
                count=0;
                res++;
            }
            c=s[i];
        }
        return res;
    }
};
