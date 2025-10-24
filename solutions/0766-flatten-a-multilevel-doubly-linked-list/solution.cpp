/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        func(nullptr,head);
        return head;
    }

    Node* func(Node* prev,Node* curr){
        if(!curr) return prev;
        curr->prev=prev;
        if(prev) prev->next=curr;

        Node* next=curr->next;
        Node* tail=func(curr,curr->child);
        curr->child=NULL;
        return func(tail,next);
    }
};
