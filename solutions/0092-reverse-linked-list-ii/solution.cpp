class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode *lpre = &dummy, *l, *r, *rsuc;
        ListNode* t = head;

        for (int i = 1; i <= right; i++) {
            if (i == left - 1) lpre = t;
            if (i == left) l = t;
            if (i == right) {
                r = t;
                rsuc = r->next;
            }
            t = t->next;
        }

        r->next = NULL; // isolate segment

        // reverse sublist [l, r]
        ListNode *prev = NULL, *curr = l, *nxt;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        lpre->next = prev; // connect prefix to new head
        l->next = rsuc;    // connect tail of reversed to suffix

        return dummy.next; // works even if left == 1
    }
};

