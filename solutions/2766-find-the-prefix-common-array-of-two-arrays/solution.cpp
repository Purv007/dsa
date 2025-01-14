class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map<int,int>count(n);
        vector<int>res(n);
        int temp=0;
        for(int i=0;i<n;i++){
            if(++count[A[i]]==2) temp++;
            if(++count[B[i]]==2) temp++;
            res[i]=temp;
        }
        return res;
    }
};
