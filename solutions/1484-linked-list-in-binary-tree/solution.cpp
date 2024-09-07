/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool preorder_left(TreeNode* root,ListNode* head) {
        //base case
        if(root == NULL) {
            return false;
        }

        // cout << root-> data << " ";
        if(recursion(head,root)){
            return true;
        }
        return preorder_left(root->left,head) || preorder_left(root->right,head);
    }
    bool recursion(ListNode* head,TreeNode* any){
        if(head==NULL){
            return true;
        }
        if (any == NULL || head->val != any->val) {
            return false;
        }
        return recursion(head->next,any->left) || recursion(head->next,any->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return preorder_left(root,head);
    }
};
