class Solution {
public:
    vector<vector<string>>res;

    bool pal(string s){
        int n=s.size()/2 +1;
        for(int i=0;i<n;i++){
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }

    void recur(string s,int i,vector<string>&t){
        if(i==s.size()){
            res.push_back(t);
            return;
        }

        for(int k=i;k<s.size();k++){
            string a=s.substr(i,k-i+1);
            if(pal(a)){
                t.push_back(a);
                recur(s,k+1,t);
                t.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>t;
        recur(s,0,t);
        return res;
    }   
};
