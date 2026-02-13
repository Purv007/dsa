class Solution {
public:
    int mono(const string &s){
        if(s.empty()) return 0;
        int count=1;
        int res=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) count++;
            else count=1;
            res=max(res,count);
        }
        return res;
    }

    int duo(const string &s,char a,char b){
        map<int,int>m;
        m[0]=-1;
        int res=0;
        int delta=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=a && s[i]!=b){
                m.clear();
                delta=0;
                m[0]=i;
                continue;
            }
            if(s[i]==a) delta++;
            else delta--;

            if(m.find(delta)!=m.end()){
                res=max(res,i-m[delta]);
            }
            else{
                m[delta]=i;
            }
        }
        return res;
    }

    int trio(const string &s){
        map<vector<int>,int>m;
        m[{0,0}]=-1;
        vector<int>cnt(3,0);
        int res=0;

        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;

            vector<int>key={cnt[1]-cnt[0],cnt[2]-cnt[0]};

            if(m.find(key)!=m.end()){
                res=max(res,i-m[key]);
            }
            else{
                m[key]=i;
            }
        }
        return res;
    }

    int longestBalanced(string s) {
        return max({mono(s),duo(s,'a','b'),duo(s,'c','b'),duo(s,'a','c'),trio(s)});
    }
};
