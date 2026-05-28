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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* s=head;
        ListNode* e=head;
        if(!head->next) return NULL;
        for(int i=n-1;i>0;i--){
            if(e->next)
                e=e->next;
        }
        ListNode* prev=NULL;
        while(e->next){
            prev=s;
            s=s->next;
            e=e->next;
        }
        if(prev)
        prev->next=s->next;
        else return s->next;
        return head;
    }
};
