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
    void reorderList(ListNode* head) {
        if(head->next==NULL) return ;
        ListNode* s=head;
        ListNode* h=head;
        while(s->next && h->next && h->next->next){
            s=s->next;
            h=h->next->next;
        }
        ListNode* l2=s->next;
        s->next=NULL;
        ListNode* prev=NULL;
        ListNode* nxt;
        while(l2->next){
            nxt=l2->next;
            l2->next=prev;
            prev=l2;
            l2=nxt;
        }
        l2->next=prev;
        h=head;
        s=l2;
        ListNode * temp1;
        ListNode * temp2;
        while(h && s){
            temp1= h->next;
            temp2=s->next;
            h->next=s;
            s->next=temp1;
            h=temp1;
            s=temp2;
        }
    }
};
