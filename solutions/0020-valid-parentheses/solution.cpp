class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        // if(st.size()%2==1) return false;
        for(auto i:st){
            if(i=='(' || i=='{' || i=='['){
                s.push(i);
            }
            else{
                if (s.empty()) return false;
                char c=s.top();
                if(c=='(' && i!=')') return false;
                else if(c=='[' && i!=']') return false;
                else if(c=='{' && i!='}') return false;
                s.pop();
            }
        }
        return s.empty();
    }
};
