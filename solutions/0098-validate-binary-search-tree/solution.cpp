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
long long temp=LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        bool l=isValidBST(root->left);
        if(root->val<=temp) return false;
        temp=root->val;
        bool r=isValidBST(root->right);
        return l && r;
    }
};
