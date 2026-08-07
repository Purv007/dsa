/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*>m;

        if(node->neighbors.size()==0){
            Node* n=new Node(node->val);
            return n;
        }
        return dfs(node,m);
    }

    Node* dfs(Node* curr,unordered_map<Node*,Node*>&m){
        vector<Node*>neigh;
        Node* clone=new Node(curr->val);
        m[curr]=clone;

        for(auto i:curr->neighbors){
            if(m.find(i)==m.end()){
                neigh.push_back(dfs(i,m));
            }
            else{
                neigh.push_back(m[i]);
            }
        }
        clone->neighbors=neigh;
        return clone;
    }
};
