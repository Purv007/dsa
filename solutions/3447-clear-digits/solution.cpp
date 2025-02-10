class Solution {
public:
    string clearDigits(string s) {
        string res;
        queue<char>q;

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                while(!q.empty()){
                    res+=q.front();
                    q.pop();
                }
                if(!res.empty())
                    res.pop_back();
            }
            else { 
                q.push(s[i]);
            }
        }
        while (!q.empty()) {
            res += q.front();
            q.pop();
        }

        return res;
    }
};
