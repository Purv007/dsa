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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* tail=head;
        int n=1;

        while(tail->next){
            tail=tail->next;
            n++;
        }

        tail->next=head;
        if(k%=n){
            for(int i=0;i<n-k;i++){
                tail=tail->next;
            }
        }
        ListNode* res=tail->next;
        tail->next=NULL;
        return res;
    }
};
