class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> ch;
        int n=s.length();
        vector<int>pair(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ch.push(i);
            }
            if (s[i] == ')') {
                int j = ch.top();
                ch.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for(int curr=0,dir=1;curr<n;curr+=dir){
            if(s[curr]=='(' || s[curr]==')'){
                dir=-dir;
                curr=pair[curr];
            }
            else{
                res+=s[curr];
            }
        }
        return res;
    }
};
