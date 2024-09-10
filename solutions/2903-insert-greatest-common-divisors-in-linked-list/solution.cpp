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
class Solution {
public:
    // void insert(ListNode* &head,ListNode* curr,int gcd){
    //     ListNode* temp=head;
    //     while(temp!=curr){
    //         temp=temp->next;
    //     }
    //     ListNode* fol=curr->next;
    //     ListNode* newnode=new ListNode(gcd);
    //     curr->next=newnode;
    //     newnode->next=fol;
    // }
    int findGCD(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* curr=head;
        ListNode* next=curr->next;
        while(next!=NULL){
            int gcd=findGCD(curr->val,next->val);
            // insert(head,curr,gcd);
            ListNode* newnode=new ListNode(gcd);
            curr->next=newnode;
            newnode->next=next;

            curr=next;
            next=next->next;
        }
        return head;
    }
};
