class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(!head || !head->next) return false;
        ListNode* r1 = head;
        ListNode* r2 = head;
        while(r1->next && r2->next && r2->next->next){
            r2 = r2->next->next;
            r1 = r1->next;
            if(r1 == r2) return true;
        }
        return false;
    }
};