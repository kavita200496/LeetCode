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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res, f;
        deque<TreeNode*> deq;
        TreeNode* cur;
        
        if (root == NULL) return res;
        deq.push_back(root);
        while (deq.size() != 0) {
            int l = deq.size();
            vector<int> level;
            
            for (int i = 0; i < l; i++) {
                cur = deq.front();
                level.push_back(cur->val);
                deq.pop_front();
                if (cur->left != NULL) deq.push_back(cur->left);
                if (cur->right != NULL) deq.push_back(cur->right);
            }
            res.push_back(level);
        }
        for (int i = 0; i < res.size(); i++) 
            f.push_back(res[res.size()-1-i]);
        
        return f;
    }
};
