
class Solution {
public:
        bool isPalindrome(ListNode* head){
            //if the first and second half reverse of each other than its a palidrome
           vector<int> list;
           while(head){
            list.push_back(head->val);
                head = head->next;
            }
            int left =0 , right = list.size()-1;
            while(left<right && list[left]==list[right]){
                left++;
                right--;
            }

           return left>=right;

    }
};