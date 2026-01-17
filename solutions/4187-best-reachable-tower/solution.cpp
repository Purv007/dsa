class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& ce, int radius) {
        // sort(towers.begin(),towers.end());
        sort(towers.begin(), towers.end(),
     [](const vector<int>& a, const vector<int>& b) {
         if (a[0] != b[0]) 
             return a[0] > b[0]; 
         return a[1] > b[1]; 
     });

        stack<pair<vector<int>,int>>s;
        for(auto a:towers){
            int x1=a[0];
            int y1=a[1];
            int q1=a[2];
            if(!s.empty() && s.top().second>q1) continue;
            int d=abs(ce[0]-x1)+abs(ce[1]-y1);
            if(d<=radius){
                vector<int>v={x1,y1};
                while(!s.empty() && s.top().second>q1){
                    s.pop();
                }
                s.push({v,q1});
            }
        }
        vector<int>temp={-1,-1};
        return s.empty()?temp:s.top().first;
    }
};
