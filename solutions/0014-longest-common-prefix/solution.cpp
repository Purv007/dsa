class Solution {
public:
    string longestCommonPrefix(vector<string>& st) {
        int n=st.size();

        int res=st[0].size();

        for(int i=1;i<n;i++){
            int temp=0;
            for(int j=0;j<st[i].size();j++){
                if(st[0][j]!=st[i][j]) break;
                if(temp==res) break;
                temp++;
            }
            res=min(temp,res);
        }
        string s=st[0].substr(0,res);
        return s;
    }
};
