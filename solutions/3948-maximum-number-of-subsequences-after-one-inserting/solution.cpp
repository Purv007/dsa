class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        vector<long long>prefix(n+1,0);
        vector<long long>suffix(n+1,0);
        
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                prefix[i+1]=1;
            }
            prefix[i+1]+=prefix[i];

        }

        for(int i=n-1;i>=0;i--){
            if(s[i]=='T'){
                suffix[i]=1;
            }
            suffix[i]+=suffix[i+1];
        }
        long long resL=0;
        long long resC=0;
        long long resT=0;
        long long idx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='C'){
                resL+=(prefix[i]+1)*suffix[i+1];
                resT+=(prefix[i])*(suffix[i+1]+1);
                resC+=prefix[i]*suffix[i+1];
            }
            else{
                idx=max(prefix[i]*suffix[i],idx);
            }
        }
        resC+=idx;
        cout<<resL<<" "<<resC<<" "<<resT<<endl;
        return max(resL,max(resC,resT));

    }
};
