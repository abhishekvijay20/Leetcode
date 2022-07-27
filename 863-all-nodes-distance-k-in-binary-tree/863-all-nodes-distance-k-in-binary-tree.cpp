/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void print (TreeNode* root, int k, vector<int>& ans) {
        if (root == NULL) return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        print(root->left, k-1, ans);
        print(root->right, k-1, ans);
    } 

    int helper (TreeNode* root, TreeNode *target, int k, vector<int>& ans) {
        if (root == NULL) return -1;
        if (root == target) {
            print(root, k, ans);
            return 0;
        }
        
        int ld = helper(root->left, target, k, ans);
        if (ld != -1) {
            if (ld+1 == k) {
                ans.push_back(root->val);
            } else {
                print(root->right, k-ld-2, ans);
            }
            return ld+1;
        }
        int rd = helper(root->right, target, k, ans);
        if (rd != -1) {
            if (rd+1 == k) {
                ans.push_back(root->val);
            } else {
                print(root->left, k-rd-2, ans);
            }
            return rd+1;
        }
        return -1;
    }
    
// void printNodesAtDepthK(TreeNode *root, int k, vector<int>& ans)
// {
//     if(root == NULL)
//         return;

//     if(k == 0)
//     {
//         ans.push_back(root->val);
//         return;
//     }

//     printNodesAtDepthK(root->left, k-1, ans);
//     printNodesAtDepthK(root->right, k-1, ans);
// }

// int print(BinaryTreeNode<int> *root, int k, TreeNode* element, vector<int>& ans)
// {
//     if(root == NULL)
//     {
//         return -1;
//     }

//     if(root == element)
//     {
//         printNodesAtDepthK(root, k, ans);
//         return 0;
//     }

//     int leftDistance = print(root->left, k, element, ans);
    
//     if(leftDistance != -1)
//     {
//         if(leftDistance+1 == k)
//         {
//             ans.push_back(root->val);
//         }
//         else
//         {
//             printNodesAtDepthK(root->right, k-leftDistance-2, ans);
//         }

//         return 1 + leftDistance;
//     }

//     int rightDistance = print(root->right, k, element, ans);

//     if(rightDistance != -1)
//     {
//         if(rightDistance+1 == k)
//         {
//             ans.push_back(root->val);
//         }
//         else
//         {
//             printNodesAtDepthK(root->left, k-rightDistance-2, ans);
//         }

//         return 1 + rightDistance;
//     }
    
//     return -1;
// }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        helper(root, target, k, ans);
        return ans;
    }
};