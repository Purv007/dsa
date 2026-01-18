class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == 0) 
                    res.push_back(curr->val);

                if (curr->right) q.push(curr->right);
                if (curr->left)  q.push(curr->left);
            }
        }
        return res;
    }
};

