class Solution {
public:
    int maxArea(vector<int>& h) {
        int res=0;
        int n=h.size();
        int i=0,j=n-1;
        while(i<j){
            res=max(res,min(h[i],h[j])*(j-i));
            if(h[i]<h[j]){
                i++;
            }
            // else if(h[i]==h[j]){
            //     if(h[i+1]>h[j-1]){
            //         i++;
            //     }else{
            //         j--;
            //     }
            // }
            else{
                j--;
            }
        }

        return res;
    }
};
