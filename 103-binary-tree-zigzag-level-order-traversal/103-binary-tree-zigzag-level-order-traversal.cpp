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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        bool flag = true;
        while (!q.empty() || !s.empty()) {
            vector<int> temp;
            if (flag) {         
                int n = q.size();
                for (int i=0; i<n; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    temp.push_back(node->val);
                    if (node->left != NULL) {
                        q.push(node->left);
                        s.push(node->left);
                    }
                    if (node->right != NULL) {
                        q.push(node->right);
                        s.push(node->right);
                    }
                }
                flag = false;
                ans.push_back(temp);
            } else {
                int n = s.size();
                for (int i=0; i<n; i++) {
                    TreeNode* node = s.top();
                    s.pop();
                    temp.push_back(node->val);                
                }
                for (int i=0; i<n; i++) {
                    TreeNode* node = q.front();
                    if (node->left != NULL) q.push(node->left);
                    if (node->right != NULL) q.push(node->right); 
                    q.pop();
                }
                flag = true;  
                ans.push_back(temp);
            }
        }
        return ans;
    }
};