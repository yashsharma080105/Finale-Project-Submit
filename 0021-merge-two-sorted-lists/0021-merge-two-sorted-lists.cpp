
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        //SC = O(n)  TC = O(nlogn)
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                temp->next =a;  //connect c with a
                a = a->next;
                temp = temp->next;

            }
            else{
                temp->next = b;
                b  = b->next;
                temp = temp->next;

            }
        }
        if(a==NULL) temp->next= b;
        else temp->next = a;
        return c->next;
}

};