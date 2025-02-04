
class Solution {
public:
    ListNode* merge(ListNode*a , ListNode* b){
        //SC = O(1)
        if(a==NULL) return b;
        if(b==NULL) return a;
        if(a->val>=b->val) b->next = merge(a,b->next);
        else{
            a->next = merge(a->next,b);
            b = a;
        }
        return b;
        
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        // to find the left middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //now slow is at left middle
        ListNode* a = head;
        ListNode* b= slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode*c = merge(a,b);
        return c;
    }
};