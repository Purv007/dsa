class Solution {
public:
    vector<TreeNode*> trees;
    unordered_map<int, TreeNode*> rts;   // root value -> root pointer

    bool isValid(TreeNode* root, long mn, long mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return isValid(root->left, mn, root->val) &&
               isValid(root->right, root->val, mx);
    }

    void traverse(TreeNode* root) {
        if (!root) return;

        if (!root->left && !root->right) {
            int val = root->val;

            if (rts.count(val)) {
                TreeNode* join = rts[val];

                root->left = join->left;
                root->right = join->right;

                rts.erase(val);
            }
        }

        traverse(root->left);
        traverse(root->right);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        this->trees = trees;

        unordered_set<int> leaves;

        for (auto t : trees) {
            rts[t->val] = t;
            if (t->left) leaves.insert(t->left->val);
            if (t->right) leaves.insert(t->right->val);
        }

        TreeNode* mainRoot = nullptr;
        for (auto t : trees) {
            if (!leaves.count(t->val)) {
                mainRoot = t;
                break;
            }
        }

        if (!mainRoot) return nullptr;

        rts.erase(mainRoot->val);

        traverse(mainRoot);

        if (!rts.empty()) return nullptr;

        if (!isValid(mainRoot, LONG_MIN, LONG_MAX)) return nullptr;

        return mainRoot;
    }
};

