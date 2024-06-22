class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        bool flag=false;
        int max=0;
        for(int i=0;i<n;i++){
            max+=customers[i];
        }
        if(n==minutes){
            return max;
        }
        for(int i=0;i<n;i++){
            if(grumpy[i]==1){
                flag=true;
                break;
            }
            else if(!flag && i==(n-1)){
                return max;
            }
        }
        flag=true;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                flag=false;
                break;
            }
            else if(flag && i==(n-1)){
                continue;
            }
        }
        int res=0;
        vector<int>vec;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                res+=customers[i];
            }
            else{
                continue;
            }
        }
        
        for(int j=0;j<n-minutes+1;j++){
            int temp=0;
            for(int k=j;k<j+minutes;k++){
                if(grumpy[k]==1){
                    temp+=customers[k];
                }
                else{
                    continue;
                }
            }
            vec.push_back(temp);
        }
            
        max=vec[0];
        for(int i=1;i<n-minutes+1;i++){
            if(vec[i]>max){
                max=vec[i];
            }
        }
        res+=max;
        return res;
    }
};
