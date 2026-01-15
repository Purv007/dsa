/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    string res = "";
    void func(TreeNode* root, string curr) {
        if (!root) return;
        char c=char('a'+root->val);
        curr+=c;
        func(root->left, curr);
        func(root->right, curr);
        if (root->left == NULL && root->right == NULL) {
            string nn(curr.rbegin(), curr.rend());
            if (res.empty() || res > nn) {
                res = nn;
            }
            return;
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        func(root, "");
        return res;
    }
};
