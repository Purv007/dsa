class Solution {
public:
vector<int>parent,size;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px==py) return true;
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            if(graph[i].empty()) continue;
            int t=graph[i][0];
            for(auto x:graph[i]){
                if(find(i)==find(x)) return false;
                unite(t,x);
            }
        }
        return true;
    }
};