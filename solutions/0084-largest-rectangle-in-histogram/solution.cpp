class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int>s;
        int res=0;
        for(int i=0;i<=n;i++){
            int curr=i<n?h[i]:0;
            res=max(res,curr);
            while(!s.empty() && h[s.top()]>curr){
                int mid=s.top();
                s.pop();
                int l=s.empty()?0:s.top()+1;
                int r=i-1;
                cout<<h[mid]*(r-l+1)<<endl;
                res=max(res,h[mid]*(r-l+1));
            }
            s.push(i);

        }
        return res;
    }
};
