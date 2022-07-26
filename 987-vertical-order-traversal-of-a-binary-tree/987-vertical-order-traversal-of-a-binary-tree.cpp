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
    void traversal(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& m) {
        if (root == NULL) return;
        
        m[x][y].insert(root->val);
        traversal(root->left, x-1, y+1, m);
        traversal(root->right, x+1, y+1, m);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        map<int, map<int, multiset<int>>> m;
        traversal(root, 0, 0, m);
        for (auto it1: m) {
            vector<int> temp;
            for (auto it2: it1.second) {
                for (auto it3: it2.second) {
                    temp.push_back(it3);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};