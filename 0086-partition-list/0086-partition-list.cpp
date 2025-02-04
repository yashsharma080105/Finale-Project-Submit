
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo  = new ListNode(100); //fake node
        ListNode* hi = new ListNode(234)  ;
        ListNode* tempLo = lo;
        ListNode* tempHi = hi;
        ListNode* temp = head;

        while(temp!=NULL){
            if(temp->val<x){
                tempLo->next = temp;  //connect
                temp =temp->next;   //step
                tempLo = tempLo->next;

            } 
            else{
                tempHi->next = temp;  //connect
                temp =temp->next;   //step
                tempHi = tempHi->next;
            }
        }
        tempLo ->next = hi->next;
        tempHi->next=NULL;
        return lo->next;

     }
};