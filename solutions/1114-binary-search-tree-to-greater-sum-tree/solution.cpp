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
    int updateTree(TreeNode* root, int valueFromParent){
        if(root == nullptr) return 0;
        int sumRight = updateTree(root->right, valueFromParent);
        int sumLeft = updateTree(root->left, root->val+valueFromParent+sumRight);
        int totalSum = root->val + sumLeft+ sumRight;
        root->val = sumRight + root->val + valueFromParent;
        return totalSum;
    }

    TreeNode* bstToGst(TreeNode* root) {
        updateTree(root,0);
        return root;
    }
};
