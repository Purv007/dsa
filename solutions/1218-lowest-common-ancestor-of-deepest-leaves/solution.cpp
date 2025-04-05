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
int maxLevel=INT_MIN;
    pair<TreeNode*,int> trav(TreeNode* root){
        if(!root){
            return {NULL,0};
        }
        
        auto left=trav(root->left);
        auto right=trav(root->right);

        if(left.second > right.second){
            cout<<"1 "<<left.first->val<<" "<<left.second+1<<endl;
            return {left.first,left.second+1};
        }
        else if(left.second < right.second){
        cout<<"2 "<<right.first->val<<" "<<right.second+1<<endl;
            return {right.first,right.second+1};
        }
        cout<<"3 "<<root->val<<" "<<left.second+1<<endl;
        return {root,left.second+1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return trav(root).first;
 
    }
};
