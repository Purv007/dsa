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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=recur(mp,inorder,0,n-1,postorder,0,n-1);
        return root;
    }
    TreeNode* recur(unordered_map<int,int> &mp,vector<int>&inorder,int ins,int ine,vector<int>&postorder,int pos,int poe){
        if(ins>ine || pos>poe) return NULL;

        TreeNode* root=new TreeNode(postorder[poe]);
        int mid=mp[postorder[poe]];
        int remaining=mid-ins;
        root->left=recur(mp,inorder,ins,mid-1,postorder,pos,pos+remaining-1);
        root->right=recur(mp,inorder,mid+1,ine,postorder,pos+remaining,poe-1);
        return root;
    }
};
