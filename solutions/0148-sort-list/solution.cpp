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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp=NULL;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        temp->next=NULL;

        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return merge(l1,l2);
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode * ptr=new ListNode(0);
        ListNode* curr=ptr;

        while(l1 && l2){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }

        while(l1){
            curr->next=l1;
            curr=curr->next;
            l1=l1->next;
        }
        while(l2){
            curr->next=l2;
            curr=curr->next;
            l2=l2->next;
        }

        return ptr->next;
    }
};
