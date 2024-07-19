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
    TreeNode* bstToGst(TreeNode* root) {
        updateTree(root,0);
        return root;
    }
    int updateTree(TreeNode* &root,int valueFromparent){
        if(root==NULL) return 0;
        int sumRight=updateTree(root->right,valueFromparent);
        int sumLeft=updateTree(root->left,root->val+sumRight+valueFromparent);
        int total=root->val+sumRight+sumLeft;
        root->val=valueFromparent+root->val+sumRight;
        return total;
    }
};
