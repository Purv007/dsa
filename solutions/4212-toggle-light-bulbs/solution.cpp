class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>m;
        for(auto i:bulbs) m[i]++;

        vector<int>res;
        for(auto [i,j]:m){
            if(j%2==1) res.push_back(i);
        }
        return res;
    }
};
