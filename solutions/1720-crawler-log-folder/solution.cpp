class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=1;
        for(auto i:logs){
            if(i=="../"){
                if(count!=1)
                    count--;
            }
            else if(i!="./")
                count++;
        }
        return count-1;
    }
};
