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
    bool isleaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    
    int sum(TreeNode* root, int& res) {
        if (root) {
            if (root->left) {
                if (isleaf(root->left)) {
                    res += (root->left->val);
                } else {
                    sum(root->left, res);
                }
            }
            if (root->right) sum(root->right, res);
        }
        return res;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        return sum(root, res);
    }
};
