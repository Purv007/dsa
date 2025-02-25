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
    TreeNode* recoverFromPreorder(string t) {
        stack<TreeNode*>s;
        int index=0;
        int n=t.size();
        while(index<n){
            int dash=0;
            while(index<n && t[index]=='-'){
                dash++;
                index++;
            }

            int value=0;
            while(index<n && isdigit(t[index])){
                value=value*10+(t[index]-'0');
                index++;
            }

            TreeNode* node=new TreeNode(value);
            if(s.empty()){
                s.push(node);
            }
            else if(s.size()<=dash){
                s.push(node);
            }
            else{
                while(s.size()>dash){
                    TreeNode* temp=s.top();
                    s.pop();
                    TreeNode* curr=s.top();
                    if(!curr->left){
                        curr->left=temp;
                    }else{
                        curr->right=temp;
                    }
                }
                s.push(node);
            }
        }

        while(s.size()>1){
            TreeNode* temp=s.top();
            s.pop();
            TreeNode* curr=s.top();
            if(!curr->left){
                curr->left=temp;
            }else{
                curr->right=temp;
            }
        }
        return s.top();
    }
};
