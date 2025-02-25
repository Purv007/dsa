class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stack = "";
        int i=0, end=s.size(), window=part.size();
        while(i<end){
            stack += s[i++];
            int stackSize = stack.size();
            if((stackSize >= window) && (stack.substr(stackSize-window, window) == part))
                stack = stack.substr(0, stackSize-window);
        }
        return stack;
    }
};
