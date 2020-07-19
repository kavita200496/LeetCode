/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string ans = to_string(t->val);
        if (t->right) ans += "("+tree2str(t->left) + ")" + "(" +tree2str(t->right) + ")";
        else if (t->left) ans += "("+tree2str(t->left)+")";
        return ans;
    }
};
