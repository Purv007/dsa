class Solution {
public:
vector<vector<string>> res;
    bool pal(string t){
        int n=t.size();
        int m=n/2;
        for(int i=0;i<=m;i++){
            if(t[i]!=t[n-i-1]) return false;
        }
        return true;
    }
    void func(vector<string>&curr,string &s,int ind){
        if(ind==s.size()){
            res.push_back(curr);
            return;
        }

        for(int i=ind;i<s.size();i++){
            string temp=s.substr(ind,i-ind+1);
            if(temp.size()==1 || pal(temp)){
                curr.push_back(temp);
                func(curr,s,i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string>temp;
        func(temp,s,0);
        return res;
    }
};
