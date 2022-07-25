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
private:
    pair<bool, int> height(TreeNode* root) {
        if (root == NULL) return {true, 0};
        
        pair<bool, int> l = height(root->left);
        pair<bool, int> r = height(root->right);
        
        if (l.first && r.first && abs(l.second - r.second) <= 1) return {true, 1 + max(l.second, r.second)};
        return {false, 1 + max(l.second, r.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root).first;
    }
};