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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 1;
        
        while (!q.empty()) {
            int qs = q.size();
            int mini = INT_MAX, maxi = 0;
            while (qs--) {
                auto node = q.front();
                q.pop();
                int x = node.second * 2;
                if (node.first->left) {
                    q.push({node.first->left, x});
                    mini = min(mini, x);
                    maxi = max(maxi, x);
                }
                if (node.first->right) {
                    q.push({node.first->right, x-1});
                    mini = min(mini, x-1);
                    maxi = max(maxi, x-1);
                }
            }
            mini = (mini == INT_MAX)?0:mini;
            ans = max((maxi-mini+1),ans);
        }
        return ans;
    }
};
