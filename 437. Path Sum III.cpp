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
    void dfs (TreeNode* root, int sum, int cur, int& count) {
        if (root) {
            cur += root->val;
            if (cur == sum) count++;
            dfs(root->left, sum, cur, count);
            dfs(root->right, sum, cur, count);
        }
    }
    void path(TreeNode* root, int sum, int& count) {
        if (root == NULL) return;
        dfs(root, sum, 0, count);
        path(root->left, sum, count);
        path(root->right, sum, count);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        path(root, sum, count);
        return count;
    }
};
