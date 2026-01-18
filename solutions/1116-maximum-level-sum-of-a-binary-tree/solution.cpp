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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int sum=INT_MIN,level=1;
        int res=1;
        while(!q.empty()){
            int n=q.size();
            int c=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                c+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(c>sum){
                sum=c;
                res=level;
            }
            level++;
        }
        return res;
    }
};
