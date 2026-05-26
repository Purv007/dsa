class Solution {
public:
vector<int> parent;
int count=0; 

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        int pa=find(a);
        int pb=find(b);

        if(pa==pb) return;
        count++;
        parent[pa]=pb;
    }

    int removeStones(vector<vector<int>>& s) {
        int n=s.size();
        parent.resize(n,-1);

        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i][0]==s[j][0] || s[i][1]==s[j][1]){
                    unite(i,j);
                }
            }
        }

        return count;
    }
};
