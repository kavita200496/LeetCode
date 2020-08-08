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
    void preorder(TreeNode* root, int level, int hd, map<int, vector<pair<int,int>>>& mp) {
        if (root == NULL) return;
        mp[hd].push_back({level, root->val});
        preorder(root->left, level+1, hd-1, mp);
        preorder(root->right, level+1, hd+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        preorder(root, 0, 0, mp);
        vector<vector<int>> v;
        
        for (auto &i : mp) {
            sort(i.second.begin(), i.second.end());
            vector<int> vertical;
            
            for (auto &p : i.second) {
                vertical.push_back(p.second);
            }
            v.push_back(vertical);
            
        }
        return v;
    }
};
