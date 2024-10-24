// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==nullptr) return root;
        root->val=0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int n=nodes.size();
            int totalSumAtLevel=0;
            vector<int> valCurr(n,0);
            for(int i=0;i<n;i++){
                int currSum=0;
                TreeNode* front=nodes.front();
                if(front->left){
                    currSum+=front->left->val;
                }
                if(front->right){
                    currSum+=front->right->val;
                }
                valCurr[i]=currSum;
                cout<<currSum<<endl;
                totalSumAtLevel+=valCurr[i];
                nodes.pop(); nodes.push(front);
            }
            for(int i=0;i<n;i++){
                TreeNode* front=nodes.front();
                if(front->left){
                    front->left->val=totalSumAtLevel-valCurr[i];
                    nodes.push(front->left);
                }
                if(front->right){
                    front->right->val=totalSumAtLevel-valCurr[i];
                    nodes.push(front->right);
                }
                nodes.pop();
            }
        }
        return root;
    }
};


/*
TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        queue<TreeNode*> nodes; 
        nodes.push(root); root->val = 0;
        while(!nodes.empty()){
            for(int i=0; i<nodes.size(); i++) {
                TreeNode* front = nodes.front(); nodes.pop();
                if(front->left) {
                    // do something
                    nodes.push(front->left);
                }
                if(front->right) {
                    // do something
                    nodes.push(front->right);
                }
            }
        }   
        return root;
*/
