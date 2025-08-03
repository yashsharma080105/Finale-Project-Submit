
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1: Create a deep copy of nodes without setting random pointers
        Node* dummy = new Node(0);  // dummy node for ease of construction
        Node* tempC = dummy;
        Node* temp = head;

        while (temp) {
            Node* newNode = new Node(temp->val);  // create a copy of current node
            tempC->next = newNode;  // link it to the copied list
            tempC = tempC->next;    // move pointer in copied list
            temp = temp->next;      // move pointer in original list
        }

        // Get the head of the copied list
        Node* copyHead = dummy->next;

        // Step 2: Create a map between original nodes and their copies
        unordered_map<Node*, Node*> nodeMap;
        Node* orig = head;
        Node* copy = copyHead;

        while (orig) {
            nodeMap[orig] = copy;  // map original to copy
            orig = orig->next;
            copy = copy->next;
        }

        // Step 3: Assign random pointers using the map
        orig = head;
        copy = copyHead;
        while (orig) {
            if (orig->random)
                copy->random = nodeMap[orig->random];
            orig = orig->next;
            copy = copy->next;
        }

        return copyHead;
    }
};
