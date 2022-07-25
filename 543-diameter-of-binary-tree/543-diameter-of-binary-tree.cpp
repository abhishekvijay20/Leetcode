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
    pair<int, int> helper (TreeNode* root) {
        // first = diameter , second = ht
        if (root == NULL) return {0, 0};
        
        pair<int, int> leftSub = helper(root->left);
        pair<int, int> rightSub = helper (root->right);
        
        int dia = leftSub.second + rightSub.second;
        int bestDia = max({leftSub.first, rightSub.first, dia});
        return {bestDia, 1 + max(leftSub.second, rightSub.second)};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).first;
    }
};