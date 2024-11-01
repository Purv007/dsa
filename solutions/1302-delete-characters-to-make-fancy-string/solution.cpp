class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        char prev=s[0];
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]==prev){
                count++;
            }else{
                prev=s[i];
                count=1;
            }
            if(count<3) ans.push_back(s[i]);
        }
        return ans;
    }
};
