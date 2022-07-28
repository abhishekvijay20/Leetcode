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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr || il > ir) return NULL;

        int i = il;
        for (; i<=ir; i++) {
            if (inorder[i] == preorder[pl]) break;
        }
        
        int j = pl + i -il;
        
        TreeNode* root = new TreeNode(preorder[pl]);
        TreeNode* l = helper(preorder, inorder, pl+1, j, il, i-1);
        TreeNode* r = helper(preorder, inorder, j+1, pr, i+1, ir);
        root->left = l;
        root->right = r;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
};