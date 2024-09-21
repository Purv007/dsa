class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int choice=0;
        string res;
        int count=-1;
        int l1=word1.size(),l2=word2.size();
        for(int i=0;i<2*min(l1,l2);i++){
            if(choice%2==0) count++;
            if(choice%2==1){
                res+=word2[count];
            }
            else{
                res+=word1[count];
            }
            choice++;
        }
        if(l1!=l2){
            int l3=max(l1,l2);
            for(int i=count+1;i<l3;i++){
                if(l1>l2){
                    res+=word1[i];
                }
                else{
                    res+=word2[i];
                }
            }
        }
        return res;
    }
};
