/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node* t = head;
        
        while (t != NULL || !s.empty()) {
            if (t->child != NULL) {
                if(t->next != NULL)
                    s.push(t->next);
                t->next = t->child;
                t->next->prev = t;
                t->child = NULL;
            } else {
            if (t->next == NULL && !s.empty()) {
                t->next = s.top();
                s.pop();
                t->next->prev = t;
            }
            }
            t = t->next;
        }
        return head;
    }
};
