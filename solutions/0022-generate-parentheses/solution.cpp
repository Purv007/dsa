class Solution {
public:
    vector<string>res;
    int n;
    void func(int diff,string &s){
        if(2*n==s.size()) {
            if(diff==0)res.push_back(s);
            return;
        }
        if(diff<0) return;

        s.push_back('(');
        func(diff+1,s);
        s.pop_back();

        if(diff>0){
            s.push_back(')');
            func(diff-1,s);
            s.pop_back();
        } 
    }

    vector<string> generateParenthesis(int n) {
        this->n=n;
        string s="";
        func(0,s);
        return res;
    }
};
