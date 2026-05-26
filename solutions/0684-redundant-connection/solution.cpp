class Solution {
public:
vector<int> parent,size;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px==py) return false;
        if(size[px]>size[py]){
            parent[py]=px;
            size[px]+=size[py];
        }
        else{
            parent[px]=py;
            size[py]+=size[px];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n);
        size.resize(n,1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &i:edges){
            int a=i[0]-1;
            int b=i[1]-1;

            if(!unite(a,b)){
                return i;
            }
        }
        return {};
    }
};
