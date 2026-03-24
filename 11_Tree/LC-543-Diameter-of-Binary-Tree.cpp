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
    int diameter = 0;
    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        diameter = max(diameter, left + right);
        int sum = 1 + max(left, right);
        return sum;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return diameter;
    }
};