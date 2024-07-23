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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for(const auto& it:descriptions){
            int parent=it[0];
            int child=it[1];
            bool isLeft=it[2];

            if(nodeMap.count(parent)==0){
                nodeMap[parent]=new TreeNode(parent);
            }
            if(nodeMap.count(child)==0){
                nodeMap[child]=new TreeNode(child);
            }

            if(isLeft){
                nodeMap[parent]->left=nodeMap[child];
            }else {
                nodeMap[parent]->right=nodeMap[child];
            }

            children.insert(child);
        }

        for(auto &i:nodeMap){
            auto& value=i.first;
            auto& node=i.second;

            if(children.find(value)==children.end()){
                return node;
            }
        }
        return nullptr;
    }
};
