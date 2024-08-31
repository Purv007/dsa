/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        //base case
        vector<int> res;
        if(root==NULL){
            return res;
        }
        traverse(root,res);
        return res;
    }
    void traverse(Node* currNode,vector<int>&res){
        if(currNode == NULL) {
        return ;
    }
    for(int i=0;i<currNode->children.size();i++)
        traverse(currNode->children[i],res);
    // postorder(root->right);
    // cout << root-> data << " ";
    res.push_back(currNode->val);
    }
};

