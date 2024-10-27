/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int> heightPerNode,lookup;
        height(root,heightPerNode);
        getAns(root,heightPerNode,lookup,0,0);
        vector<int> res(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            res[i]=lookup[queries[i]];
        }
        return res;
    }

    int height(TreeNode* root,unordered_map<int,int> &heightPerNode){
        if(root==NULL) return -1;
        int left=height(root->left,heightPerNode);
        int right=height(root->right,heightPerNode);
        return heightPerNode[root->val]=max(left,right) +1;
    }

    void getAns(TreeNode* root,unordered_map<int,int> &heightPerNode,unordered_map<int,int> &lookup,int soFar,int level){
        if(root==nullptr) return;
        lookup[root->val]=soFar;
        getAns(root->left,heightPerNode,lookup,max(soFar,
        (root->right!=nullptr)? heightPerNode[root->right->val]+level+1: level),level+1);
        getAns(root->right,heightPerNode,lookup,max(soFar,
        (root->left!=nullptr)? heightPerNode[root->left->val]+level+1: level),level+1);
    }
};
