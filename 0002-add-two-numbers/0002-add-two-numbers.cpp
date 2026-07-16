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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        int sum = 0;
        ListNode dummy;
        ListNode* tail = &dummy;
        while(n1 || n2 || carry){
            
            sum = carry;

            if(n1){
                sum += n1->val;
            }
            if(n2){
                sum += n2->val;
            }
            
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if(n1) n1 = n1->next;
            if(n2) n2 = n2->next;
        }

        return dummy.next;
    }
};