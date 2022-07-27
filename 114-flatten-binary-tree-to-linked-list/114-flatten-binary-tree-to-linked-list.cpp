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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *a = root->left;
        TreeNode *b = root->right;
        root->left = NULL;
        if (a != NULL) root->right = a;
        while (a != NULL && a->right != NULL) {
            a = a->right;
        }
        if (a != NULL) a->right = b;
    }
};