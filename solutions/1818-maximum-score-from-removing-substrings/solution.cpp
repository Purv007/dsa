class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res=0;
        string highPrior= x > y ?"ab" : "ba";
        string lowPrior= highPrior=="ab" ? "ba" : "ab";

        string s1=removeSubstring(s,highPrior);
        int removedS1=(s.length()-s1.length())/2;
        res+=removedS1*max(x,y);


        string s2=removeSubstring(s1,lowPrior);
        int removedS2=(s1.length()-s2.length())/2;
        res+=removedS2*min(x,y);

        return res;
    }

    private:
    string removeSubstring(const string& s, const string& substringRemove){
        stack<char> st;
        string remaining;
        for(auto ch:s){
            if(ch==substringRemove[1] && !st.empty() && st.top()==substringRemove[0]){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        while(!st.empty()){
            remaining+=st.top();
            st.pop();
        }
        reverse(remaining.begin(),remaining.end());
        return remaining;
    }
};
