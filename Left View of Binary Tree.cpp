void solve (Node *root, int level, int& count) {
    if (!root) return;
    if (level > count) {
        cout<<root->data<<" ";
        count += 1;
    }
    solve (root->left, level+1, count);
    solve(root->right, level+1, count);
}
void leftView(Node *root)
{
   int count = 0;
   solve(root, 1, count);
}
