class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        ListNode* s = head, *e = head;
        for(int i=0; i<n; i++)
            e = e->next;
        ListNode* prev = NULL;
        while(e){
            prev = s;
            s = s->next;
            e = e->next;
        }
        if(prev) prev->next = s->next;
        else return s->next;
        return head;
    }
};