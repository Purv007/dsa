class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>pre(n+1,0);

        for(int i=0;i<n;i++){
            pre[i+1]=pre[i] + (s[i]-'0');
        }

        vector<int>pos,digit;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                pos.push_back(i);
                digit.push_back(s[i]-'0');
            }
        }

        int m=digit.size();
        vector<long long>hash(m+1,0),pow10(m+1,1);

        for(int i=0;i<m;i++){
            hash[i+1]=(hash[i]*10 + digit[i]) % MOD;
            pow10[i+1]=(pow10[i]*10)%MOD;
        }

        vector<int>res;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            int sum=pre[r+1]-pre[l];

            auto it1=lower_bound(pos.begin(),pos.end(),l);
            auto it2=upper_bound(pos.begin(),pos.end(),r);

            if(it1==pos.end() || it1==it2){
                res.push_back(0);
                continue;
            }

            int L=it1-pos.begin();
            int R=(it2-pos.begin())-1;

            long long val=(hash[R+1] - 
                hash[L]*pow10[R-L+1] % MOD +
                MOD) % MOD;

            res.push_back(val*sum % MOD);
        }
        return res;
    }
};
