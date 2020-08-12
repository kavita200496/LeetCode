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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tmp = head;
        
        while (tmp->next != NULL) {
            ListNode* t = tmp->next;
            while (t != NULL) {
                if (tmp->val > t->val) swap(tmp->val, t->val);
                t = t->next;
            }
            tmp = tmp->next;
        }
        return head;
    }
};
