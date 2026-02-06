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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*>q;
        q.push_back(root);
        bool r=true;
        vector<vector<int>>res;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode* t;
                if(r){ 
                    t=q.front();
                    q.pop_front();
                    if(t->left) q.push_back(t->left);
                    if(t->right) q.push_back(t->right);
                }
                else{ 
                    t=q.back();
                    q.pop_back();
                    if(t->right) q.push_front(t->right);
                    if(t->left) q.push_front(t->left);
                }

                temp.push_back(t->val);

            }
            res.push_back(temp);
            r=!r;
        }
        return res;
    }
};
