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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        int len=count/k;
        cout<<len<<endl;
        int extra=count%k;
        vector<ListNode*> res(k,nullptr);
        ListNode* curr=head;
        for(int i=0;i<k && curr!=NULL;i++){
            res[i]=curr;
            int size=len+(extra>0 ?1 : 0);
            extra--;

            for(int j=1;j<size;j++){
                if(curr!=nullptr){
                    curr=curr->next;
                }
            }

            if(curr!=NULL){
                ListNode* nxt=curr->next;
                curr->next=NULL;
                curr=nxt;
            }
        }
        return res;
    }
};
