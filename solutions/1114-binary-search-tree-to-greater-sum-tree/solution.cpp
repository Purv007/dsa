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
        func(root,0);
        return root;
    }
    int func(TreeNode* root,int valParent){
        if(!root){
            return 0;
        }
        int right=func(root->right,valParent);
        int left=func(root->left,root->val+valParent+right);
        int total=root->val+left+right;
        root->val=valParent+root->val+right;
        return total;
    }
};
