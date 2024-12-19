class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        for(auto i:arr){
            if(s.empty() || i>s.top()) s.push(i);
            else{
                int maxi=s.top();
                while(!s.empty() && i<s.top()){
                    s.pop();
                }
                s.push(maxi);
            }
        }
        return s.size();
    }
};
