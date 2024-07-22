class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int people=names.size();
        vector<string>sortedNames(people);
        vector<int> sortedIndices(people);
        iota(begin(sortedIndices), end(sortedIndices), 0);

        sort(sortedIndices.begin(),sortedIndices.end(),
        [&heights](int a,int b){return heights[a] > heights[b] ;});

        for(int i=0;i<people;i++){
            sortedNames[i]=names[sortedIndices[i]];
        }
        return sortedNames;
    }
};
