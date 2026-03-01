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

    void func(trie* root,string &res){
        if(root->count!=1 || root->isTerminal) return;

        for(int i=0;i<26;i++){
            if(root->child[i]!=NULL){
                res+=root->child[i]->val;
                func(root->child[i],res);
                break;
            }
        }
        return;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();

        for(auto i:strs){
            insert(root,i);
        }
        if(root->isTerminal) return "";
        string res="";
        func(root,res);
        return res;
    }
};
