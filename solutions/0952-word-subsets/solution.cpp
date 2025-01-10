class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        vector<int>maxFreq(26);

        for(auto i:words2){
            vector<int>freq(26);
            for(auto c:i){
                freq[c-'a']++;
                maxFreq[c-'a']=max(maxFreq[c-'a'],freq[c-'a']);
            }
        }

        for(auto i:words1){
            vector<int>freq(26);
            for(auto c:i){
                freq[c-'a']++;
            }
            bool valid=true;
            for(int i=0;i<26;i++){
                if(freq[i]<maxFreq[i]){
                    valid=false;
                    break;
                }
            }
            if(valid){
                res.push_back(i);
            }
        }
        return res;
    }
};
