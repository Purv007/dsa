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
    void func(TreeNode* &root,int num,int dash){
        TreeNode* nn=new TreeNode(num);
        if(root==NULL) {
            root=nn;
            return;
        }
        TreeNode* temp=root;
        for(int i=0;i<dash-1;i++){
            if(temp->right){
                temp=temp->right;
            }
            else if(temp->left){
                temp=temp->left;
            }
            else return;
        }
        if(temp->left == nullptr) {
            temp->left = nn;
        } else {
            temp->right = nn;
        }
    }
    TreeNode* recoverFromPreorder(string t) {
        TreeNode* root=NULL;
        int n=t.size();
        int count=0;
        string temp="";
        for(int i=0;i<n;i++){
            if(isdigit(t[i])){
                temp+=t[i];
                if(i+1<n && t[i+1]=='-'){
                    func(root,stoi(temp),count);
                    count=0;
                    temp="";
                }
            }
            else{
                count++;
            }
        }

        if (!temp.empty()) {
            func(root, stoi(temp), count);
        }

        return root;
    }
};
