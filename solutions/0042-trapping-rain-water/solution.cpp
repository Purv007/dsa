class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int global = max_element(h.begin(), h.end()) - h.begin();

        int res=0;
        int mx=0;
        for(int i=0;i<global;i++){
            if(h[i]>=mx){
                mx=h[i];
            }
            else{
                res+=mx-h[i];
            }
        }

        mx=0;
        for(int i=n-1;i>global;i--){
            if(h[i]>=mx){
                mx=h[i];
            }
            else{
                res+=mx-h[i];
            }
        }
        return res;
    }
};
