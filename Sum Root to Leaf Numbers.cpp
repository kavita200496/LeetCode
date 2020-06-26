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
    void sum(TreeNode* root, int curr, int& res) {
        if (root == NULL) return;
        
        curr = 10*curr + root->val;
        if (root->left == NULL && root->right == NULL) {
            res += curr;
            return;
        }
        sum(root->left, curr, res);
        sum(root->right, curr, res);
    }
    
    int sumNumbers(TreeNode* root) {
        int res = 0;
        sum(root, 0, res);
        
        return res;
    }
};
