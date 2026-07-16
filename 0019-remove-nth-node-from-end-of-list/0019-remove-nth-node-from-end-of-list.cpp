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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* t = head;
        while(t != NULL){
            l++;
            t = t->next;
        }
        int f = l-n;

        if(f == 0){
            return head->next;
        }
        ListNode* te = head;
        for(int i = 0; i < f-1; i++){
            te = te->next;
        }

        te->next = te->next->next;
        return head;
    }
};