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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // how to reverse a linked list??
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = second;
        
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head;
        ListNode* sec = prev;
        while(sec){
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec->next;

            first->next = sec;
            sec->next = temp1;

            first = temp1;
            sec = temp2;
        }


    }
};