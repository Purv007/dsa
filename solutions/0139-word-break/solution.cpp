class trie{
    public:
    char val;
    trie* child[26];
    bool isTerminal;
    int count;
    trie(char ch){
        val = ch;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isTerminal=false;
        count=0;
    }
};

class Solution {
public:
    trie* root=new trie('\0');
    void insert(trie* root,string s){
        if(s.size()==0){
            root->isTerminal=true;
            return;
        }

        int idx=s[0]-'a';
        trie* child;
        if(root->child[idx]!=NULL){
            child=root->child[idx];
        }
        else{
            child=new trie(s[0]);
            root->count++;
            root->child[idx]=child;
        }

        insert(child,s.substr(1));
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &word : wordDict)
            insert(root,word);

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++) {
            if(!dp[i]) continue;

            trie* node = root;
            for(int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if(node->child[idx] == NULL)
                    break;

                node = node->child[idx];

                if(node->isTerminal)
                    dp[j + 1] = true;
            }
        }

        return dp[n];
    }
};
