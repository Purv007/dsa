class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>>minHeap;
        unordered_set<long>visited;
        vector<int>prime={2,3,5};

        minHeap.push(1);
        visited.insert(1);

        long curr_ugly=1;
        for(int i=0;i<n;i++){
            curr_ugly=minHeap.top();
            minHeap.pop();

            for(auto i:prime){
                long next=curr_ugly*i;
                if(visited.find(next)==visited.end()){
                    minHeap.push(next);
                    visited.insert(next);
                }
            }
        }
        return curr_ugly; 
    }
};
