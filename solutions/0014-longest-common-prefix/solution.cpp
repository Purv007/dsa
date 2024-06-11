class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        string res="";
        string first=strs[0];
        int count[200];
        for(int i=1;i<strs.size();i++){
            count[i-1]=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]==first[j]){
                    count[i-1]++;
                }
                else{
                    break;
                }
            }
        }
        int min=count[0];
        for(int i=0;i<strs.size()-1;i++){
            if(count[i]<min){
                min=count[i];
            }
        }
        
        for(int i=0;i<min;i++){
            res+=strs[0][i];
        }
        return res;
    }
};
