class Solution {
public:
    bool check(string &part,stack<char>&st){
        stack<char>temp=st;
        int m=part.size();
        for(int i=m-1;i>=0;i--){
            if(temp.top()!=part[i]){ 
                return false;
            }
            temp.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        int n=s.size(),m=part.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);

            if(st.size()>=m && check(part,st)){
                for(int j=0;j<m;j++) st.pop();
            }
        }

        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }

        return res;
    }
};
