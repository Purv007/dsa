class Solution {
public:
    int compress(vector<char>& chars) {
        int res=0;
        int n=chars.size();
        int count=0;
        char c=chars[0];
        for(int i=0;i<n;i++){
            if(chars[i]==c){
                count++;
                continue;
            }
                chars[res++]=c;
                if(count>1) {
                    string s=to_string(count);
                    for(auto k:s){
                        chars[res++]=k;
                    }
                }
                c=chars[i];
                count=1;
            
        }
        chars[res++]=c;
                if(count>1) {
                    string s=to_string(count);
                    for(auto k:s){
                        chars[res++]=k;
                    }
                }
        return res;
    }
};
