/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
#define null nullptr
#define node TreeNode
    void solve(node* root) {
        if (root == null)
            return;
        swap(root->left, root->right);
        solve(root->left);
        solve(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == null)
            return root;
        solve(root);
        return root;
    }
};