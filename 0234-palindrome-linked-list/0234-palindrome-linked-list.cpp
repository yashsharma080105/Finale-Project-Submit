
class Solution {
public:
     ListNode* reverseList(ListNode* head){
        ListNode* prev =NULL,*curr = head,*Next = head;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;

        }
        return prev;
    }
        bool isPalindrome(ListNode* head){
            //if the first and second half reverse of each other than its a palidrome
            ListNode* slow = head;
            ListNode* fast =head;
            while(fast->next!=NULL && fast->next->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            //slow is at the middle
            ListNode* newHead = reverseList(slow->next);
            ListNode* a = head;
            ListNode* b = newHead;
            while(b){
                if(a->val!=b->val) return false;
                a = a->next;
                b = b->next;
            }
            return true;

    }
};