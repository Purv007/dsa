class Solution {
public:
    int n, m;
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py){
            return true;
        }

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        parent.resize(n * m);
        rank.resize(n * m, 0);

        for (int i = 0; i < n * m; i++)
            parent[i] = i;

        vector<pair<int,int>> dir = {{0,1}, {1,0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                for (auto [dx, dy] : dir) {
                    int x = i + dx;
                    int y = j + dy;

                    if (x < n && y < m && grid[i][j] == grid[x][y]) {
                        int id1 = i * m + j;
                        int id2 = x * m + y;

                        if (unite(id1, id2))
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
