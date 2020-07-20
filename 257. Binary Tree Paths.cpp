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
    vector<string> res;
    
    void binary(TreeNode* root, string tmp) {
        if (root == NULL) return;
        
        tmp += to_string(root->val);
        tmp += "->";
        if (root->left == NULL && root->right == NULL) {
            tmp[tmp.size()-1] = '\0';
            tmp[tmp.size()-2] = '\0';
            res.push_back(tmp);
            tmp = "";
        } else {
            binary(root->left, tmp);
            binary(root->right, tmp);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return res;
        binary(root, "");
        return res;
    }
};
