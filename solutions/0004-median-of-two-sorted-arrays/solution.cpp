class Solution {
public:
int func(vector<int>&A,vector<int>&B,int k,int as,int ae,int bs,int be){
    if(ae<as) return B[k-as];
    if(be<bs) return A[k-bs];

    int ai=(as+ae)/2,bi=(bs+be)/2;
    int av=A[ai],bv=B[bi];

    if(ai+bi<k){
        if(av>bv){
            return func(A,B,k,as,ae,bi+1,be);
        }
        else return func(A,B,k,ai+1,ae,bs,be);
    }
    else{
        if(av>bv){
            return func(A,B,k,as,ai-1,bs,be);
        }
        else return func(A,B,k,as,ae,bs,bi-1);
    }
    return -1;
}
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n=A.size(),m=B.size();
        int a=n+m;
        if(a%2){
            return func(A,B,a/2,0,n-1,0,m-1);
        }
        else{
            return 1.0*
            (func(A,B,a/2-1,0,n-1,0,m-1)+func(A,B,a/2,0,n-1,0,m-1))/2;
        }
        return -2;
    }
};
