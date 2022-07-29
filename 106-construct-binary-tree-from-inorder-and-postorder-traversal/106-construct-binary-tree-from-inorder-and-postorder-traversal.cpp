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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr || il > ir) return NULL;

        int i = il;
        for (; i<=ir; i++) {
            if (inorder[i] == postorder[pr]) break;
        }
        
        int j = i-il-1;
        
        TreeNode* l = helper(postorder, inorder, pl, pl+j, il, i-1);
        TreeNode* r = helper(postorder, inorder, pl+j+1, pr-1, i+1, ir);
        TreeNode* root = new TreeNode(postorder[pr]);
        // cout << "root-> " << root->val << endl;
        root->left = l;
        root->right = r;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return helper(postorder, inorder, 0, n-1, 0, n-1);        
    }
};