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
class Solution
{
public:
    bool func(TreeNode *root, int targetSum, int sum)
    {
        // base case
        if (root == nullptr)
        {
            return false;
        }
        sum = sum + root->val;
        if (root->left == nullptr && root->right == nullptr && sum == targetSum)
        {
            return true;
        }
        return (func(root->left, targetSum, sum) ||
                func(root->right, targetSum, sum));
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return func(root, targetSum, 0);
    }
};