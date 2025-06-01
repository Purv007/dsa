class Solution {
public:
    
    void bfs(int start, vector<int>& edges, vector<int>& dist) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int d = 0;
        int node = start;

        while (node != -1 && !visited[node]) {
            dist[node] = d++;
            visited[node] = true;
            node = edges[node];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,INT_MAX),dist2(n,INT_MAX);

        bfs(node1,edges,dist1);
        bfs(node2,edges,dist2);

        int res=-1,temp=INT_MAX;
        for(int i=0;i<n;i++){
            if(temp>max(dist1[i],dist2[i])){
                res=i;
                temp=max(dist1[i],dist2[i]);
            }
        }
        return res;
    }
};
