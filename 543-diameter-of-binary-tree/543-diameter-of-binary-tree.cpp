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
    int helper (TreeNode* root, int& maxi) {
        if (root == NULL) return 0;
        
        int leftSub = helper(root->left, maxi);
        int rightSub = helper (root->right, maxi);
    
        maxi = max(maxi, leftSub + rightSub);
        return 1 + max(leftSub, rightSub);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        helper(root, maxi);
        return maxi;
    }
};