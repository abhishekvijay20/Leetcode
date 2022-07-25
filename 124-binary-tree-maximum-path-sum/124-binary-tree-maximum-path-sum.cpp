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
        
        int l = helper (root->left, maxi);
        int r = helper (root->right, maxi);

        int x = 0;
        if (l >= 0) x += l;
        if (r >= 0) x += r;
        maxi = max(maxi, root->val + x);
        
        int ans = root->val;
        if (max(l, r) >= 0) ans += max(l, r); 
        return ans;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};