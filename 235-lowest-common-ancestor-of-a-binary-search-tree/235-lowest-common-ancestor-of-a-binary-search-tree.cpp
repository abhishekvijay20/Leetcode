/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        int x = min(p->val, q->val), y = max(p->val, q->val);
        
        if (x <= root->val && root->val <= y) {
            return root;
        } else if (x < root->val && y < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (x > root->val && y > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return NULL;
    }
};