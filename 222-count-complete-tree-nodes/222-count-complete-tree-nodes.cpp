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
    int lHeight(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + lHeight(root->left);
    }
    int rHeight(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + rHeight(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        
        int lh = lHeight(root);
        int rh = rHeight(root);
        
        if (lh != rh) {
            return 1 + countNodes(root->left) + countNodes(root->right);
        } else {
            return (1<<lh)-1;
        }
    }
};