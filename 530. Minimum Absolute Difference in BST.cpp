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
    vector<int> v;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        
        int mini = INT_MAX;
        int n = v.size();
        if (n == 0) return 0;
        
        for (int i = 0; i < n-1; i++) {
            mini = min(mini, v[i+1]-v[i]);
        }
        return mini;
    }
};
