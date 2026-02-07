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
    void build(TreeNode* &root,vector<int>&pre,int &i,int l,int h){
        if(i==pre.size()) return;
        if(pre[i]<l || pre[i]>h) return;

        root=new TreeNode(pre[i++]);
        build(root->left,pre,i,l,root->val);
        build(root->right,pre,i,root->val,h);
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root=NULL;
        int i=0;
        build(root,pre,i,INT_MIN,INT_MAX);
        return root;
    }
};
