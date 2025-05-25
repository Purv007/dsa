class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int pairs=0;
        unordered_map<string,int>m;

        for(auto &i:words){
            if(i[0]==i[1]) {
                m[i]++;
                continue;
            }
            else{
                string s = string() + i[1] + i[0];
                if(m[s]>0){
                    pairs++;
                    m[s]--;    
                }
                else{
                    m[i]++;
                }
                continue;
            }
        }

        int rep=0;
        bool flag=true;
        for(auto &i:m){
            string s=i.first;
            int count=i.second;
            if(s[0]==s[1]) {
                cout<<"S "<<s<<endl;
                if(flag && count%2!=0){
                    rep+=count;
                    flag=false;
                }
                else{
                    if(count%2){
                        rep+=count-1;
                    }else{
                        rep+=count;
                    }
                }
            }
        }
        return (pairs*4 + rep*2);
    }
};
