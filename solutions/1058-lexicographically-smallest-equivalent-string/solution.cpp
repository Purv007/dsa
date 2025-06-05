class Solution {
public:
    void trans(vector<vector<bool>>& v,int b,int c){
        for(int a=0;a<26;a++){
            if(v[a][b]){
                for(int j=0;j<26;j++){
                    if(v[a][j]){
                        v[j][c]=true;
                        v[c][j]=true;
                    }
                }
            }
        }
    }
    int num(char x){
        return x-'a';
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
    vector<vector<bool>> v(26, vector<bool>(26, false));


        for(int i=0;i<n;i++){
            int c1=num(s1[i]);
            int c2=num(s2[i]);
            v[c1][c2]=true;
            v[c2][c1]=true;
            trans(v,c1,c2);
            trans(v,c2,c1);
        }

        string res="";

        for(auto c:baseStr){
            int curr=num(c);
            for(int i=0;i<26;i++){
                if(v[i][curr]){
                    int minChar=i;
                    for(int j=0;j<26;j++){
                        if(v[i][j]){
                            minChar=min(minChar,j);
                            res += (char)(minChar + 'a');
                            i=30;
                            break;
                        }
                    }
                }
                if(i==25){
                    res+=c;
                }
            }
        }
        return res;
    }
};
