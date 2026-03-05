class Solution {
public:
int n,m,c;

    void func(vector<vector<int>>& image,int x,int y,int &color){
        if(x<0 || y<0 || x>=n || y>=m || image[x][y]!=c) return;

        image[x][y]=color;

        func(image,x-1,y,color);
        func(image,x+1,y,color);
        func(image,x,y-1,color);
        func(image,x,y+1,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->c=image[sr][sc];
        this->n=image.size();
        this->m=image[0].size();

        if(c==color) return image;
        func(image,sr,sc,color);
        return image;
    }
};
