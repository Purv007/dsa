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
class FindElements {
public:
    TreeNode* tree;
    unordered_set<int>present;
    void trav(TreeNode* root){
        if(root==nullptr){
            return;
        }
        if(root->left){
            root->left->val=((root->val)*2)+1;
            present.insert(root->left->val);
            trav(root->left);
        }
        if(root->right){
            root->right->val=((root->val)*2)+2;
            present.insert(root->right->val);
            trav(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        present.insert(0);
        trav(root);
    }
    
    bool find(int target) {
        return present.count(target)>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
