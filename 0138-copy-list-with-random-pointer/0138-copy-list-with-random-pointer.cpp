/*
class Node {
public:
    int val;
    Node* next;
    Node* random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Step 1 -> Create the deep copy without random pointer
        Node* dummy = new Node(0);
        Node* tempC = dummy;
        Node* temp = head;
        while(temp){
            Node* a = new Node(temp->val);
            tempC->next =  a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        // step 2 -> alternate connection
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(-1);
        Node* tempD = dummy;
        while(a){
            tempD -> next = a;
            a = a->next;
            tempD = tempD->next;
            tempD -> next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy ->next;
        // step3 -> making alternative connections
        Node* t1 = dummy;  //t1 will traverse in the original list
        while(t1){
            Node* t2 = t1->next;   //t2 is for duplicate
            if(t1->random ) t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        //Step 4 removing the connection(sperate)
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);
        t1 = d1;
        Node* t2 = d2;
        Node* t = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 =d1->next;  //original with random
        d2 = d2->next;  // dublicate with random
        return d2;


    }
};