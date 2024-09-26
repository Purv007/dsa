class TrieNode{
    public:
    int data;
    TrieNode* children[10];
    int childCount;

    TrieNode(int d){
        data=d;
        for(int i=0;i<10;i++){
            children[i]=NULL;
        }
        childCount=0;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return ;
        }

        //assumption : only capital letters
        int index=word[0]-'0';
        TrieNode* child;

        //present
        if(root->children[index] !=NULL){
            child = root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->childCount++;
            root->children[index]=child;
        }

        //recursion
        insertUtil(child,word.substr(1));
    }

    void insertWord(int num){
        string word=to_string(num);
        insertUtil(root,word);
    }

    int findlcp(int n){
        TrieNode* node=root;
        string numStr=to_string(n);
        int len=0;

        for(char digit:numStr){
            int index=digit-'0';
            if(node->children[index]){
                len++;
                node=node->children[index];
            }
            else{
                break;
            }
        }
        return len;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t=new Trie();

        for(auto i:arr1){
            t->insertWord(i);
        }

        int lcp=0;

        for(int num:arr2){
            int len=t->findlcp(num);
            lcp=max(len,lcp);
        }
        return lcp;
    }
};
