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
    int p;
    unordered_map<int,int>m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        p=0;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return func(preorder,0,n-1);
    }

    TreeNode* func(vector<int>&pre,int l,int r){
        if(l>r) return NULL;

        int val=pre[p++];
        TreeNode* root=new TreeNode(val);
        int mid=m[val];

        root->left=func(pre,l,mid-1);
        root->right=func(pre,mid+1,r);
        return root;
    }
};
