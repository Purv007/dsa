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
    unordered_map<int,int>m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return func(inorder,postorder,0,n-1,0,n-1);
    }
    TreeNode* func(vector<int>&in,vector<int>&post,int li,int ri,int lp,int rp){
        if(li>ri || lp>rp) return NULL;

        int val=post[rp];
        TreeNode* root=new TreeNode(val);
        int mid=m[val];
        int left=mid-li;

        root->left=func(in,post,li,mid-1,lp,lp+left-1);
        root->right=func(in,post,mid+1,ri,lp+left,rp-1);
        return root;
    }
};
