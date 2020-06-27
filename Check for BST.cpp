/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return true if the given tree is a BST, else return false
bool check (Node* root, int min, int max) {
    if (!root) return true;
    if (root->data < min || root->data > max) return false;
    else {
        check(root->left, min, root->data-1) &&
        check(root->right, root->data+1, max);
    }
}

bool isBST(Node* root) {
    return check(root, INT_MIN, INT_MAX);
}
