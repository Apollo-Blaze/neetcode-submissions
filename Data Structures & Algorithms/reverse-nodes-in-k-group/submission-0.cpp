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
    ListNode* getKth(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr->next;
            k--;
        }
        return curr;  
    }
    ListNode* reverse(ListNode* head,ListNode* tail){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head;
        while(curr!=tail){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head->next=tail;
        return prev;    
    } 
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while(true){
            ListNode* kth = getKth(groupPrev, k);
            if(!kth) break;
            ListNode* groupNext = kth->next;
            reverse(groupPrev->next, groupNext);
            ListNode* tail = groupPrev->next;
            groupPrev->next = kth;  
            tail->next = groupNext;
            groupPrev = tail;
        }
        return dummy->next;
    }
};
