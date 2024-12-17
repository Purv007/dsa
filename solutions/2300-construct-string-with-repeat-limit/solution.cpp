class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>count;
        for(auto c:s){
            count[c]++;
        }

        priority_queue<char>pq;
        for(auto [a,b]:count){
            pq.push(a);
        }

        string res;
        while(!pq.empty()){
            char c=pq.top();
            pq.pop();
            int use=min(count[c],repeatLimit);
            res.append(use,c);

            count[c]-=use;

            if(count[c]>0 && !pq.empty()){
                char next=pq.top();
                pq.pop();

                res+=next;
                count[next]--;
                if(count[next]>0) pq.push(next);
                pq.push(c);
            }
        }

        return res;
    }
};
