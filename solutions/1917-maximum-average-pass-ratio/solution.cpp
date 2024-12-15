class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain=[](int pass,int total){
            return (double)(pass+1)/(total+1) - (double)pass/total;
        };

        priority_queue<pair<double,pair<int,int>>>pq;

        for(auto c:classes){
            pq.push({gain(c[0],c[1]),{c[0],c[1]}});
        }

        while(extraStudents--){
            auto [maxGain,classInfo]=pq.top();
            pq.pop();

            int pass=classInfo.first;
            int total=classInfo.second;
            pass++;
            total++;
            pq.push({gain(pass,total),{pass,total}});
        }

        double passSum=0;
        while(!pq.empty()){
            auto [a,b]=pq.top();
            pq.pop();
            passSum+=(double)b.first/b.second;
        }

        return passSum/classes.size();
    }
};
