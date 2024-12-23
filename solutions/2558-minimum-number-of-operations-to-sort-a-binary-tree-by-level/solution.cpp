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
    int minimumOperations(TreeNode* root) {
        if(root==nullptr) return 0;
        int res=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            vector<int>idx(levelsize);
            iota(idx.begin(),idx.end(),0);
            vector<int>vals(levelsize);
            for(int i=0;i<levelsize;i++){
                TreeNode* front=q.front();
                q.pop();
                vals[i] = front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            sort(idx.begin(), idx.end(), [&](int i, int j){
                return vals[i]<vals[j];
            });
            for(int i=0;i<levelsize;){
                int j=idx[i];
                if(j!=i){
                    res++;
                    swap(idx[i],idx[j]);
                }
                else i++;
            }
        }
        return res;
    }
};

