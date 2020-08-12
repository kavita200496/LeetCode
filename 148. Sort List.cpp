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
    ListNode* merge(ListNode *head1, ListNode *head2)
    {
if (!head1) return head2;
    if (!head2) return head1;
    
    if (head2->val < head1->val) {
        ListNode* tmp = head1;
        head1 = head2;
        head2 = tmp;
    }
    
    ListNode* tmp1 = head1; ListNode* tmp2 = head2;
    ListNode* s; ListNode* t1 = tmp1;
    
    while (tmp1 != NULL && tmp2 != NULL) {
        
        if (tmp1->val > tmp2->val) {
            //t2 = tmp2;
                s = tmp2->next;
                t1->next = tmp2;
                tmp2->next = tmp1;
                t1 = tmp2;
                tmp2 = s;
                
            } else {
                t1 = tmp1;
                tmp1 = tmp1->next;
            }
    }
    if (tmp1 == NULL && tmp2 != NULL) {
        t1 ->next = tmp2;
    }
    return head1;
}
    
    ListNode* find_middle(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;
        ListNode* p;
        
        while (fast != NULL && fast->next != NULL) {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        p->next = NULL;
        return slow;
    }
    
    ListNode* mergesort (ListNode* node) {
       if (!node || !node->next) return node;
        ListNode* h1 = node;
        ListNode* h2 = find_middle(node);
        
        h1 = mergesort(h1);
        h2 = mergesort(h2);
        
        ListNode* sorted = merge(h1, h2);
        return sorted;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* h = mergesort(head);
        return h;
    }
};
