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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            long count = queue.size();
            long sum = 0;
            
            for (long i = 0; i < count; i++) {
                TreeNode* n = queue.front();
                queue.pop();
                sum += n->val;
                if (n->left != NULL) queue.push(n->left);
                if (n->right) queue.push(n->right);
            }
            res.push_back(sum*1.0/count);
        }
        return res;
    }
};
