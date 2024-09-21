class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumebrs;
        for(int start=1;start<=9;++start){
            generateLexicalNumbers(start,n,lexicographicalNumebrs);
        }
        return lexicographicalNumebrs;
    }

    void generateLexicalNumbers(int currNo,int limit,vector<int>&result){
        if(currNo>limit) return;

        result.push_back(currNo);

        for(int nxt=0;nxt<=9;++nxt){
            int nxtNo=10*currNo +nxt;
            if(nxtNo<=limit){
                generateLexicalNumbers(nxtNo,limit,result);
            }
            else{
                break;
            }
        }
    }
};
