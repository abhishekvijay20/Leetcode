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
    int countNode(TreeNode* root) {
        if (root == NULL) return 0;
        int lAns = countNode(root->left);
        int rAns = countNode(root->right);
        return lAns + rAns + 1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int nodesLeft = countNode(root->left);
        if (k == nodesLeft + 1) return root->val;
        
        if (k <= nodesLeft) {
            return kthSmallest(root->left, k);
        }
        return kthSmallest(root->right, k - (nodesLeft + 1));
    }
};