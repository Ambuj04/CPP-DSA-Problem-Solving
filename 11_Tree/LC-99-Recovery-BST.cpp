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
    int mistakes = 0;
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev = nullptr;
    void solve(TreeNode *root)
    {
        if (root == nullptr)
            return;
        solve(root->left);
        if (prev == nullptr)
        {
            prev = root;
        }
        else
        {
            if (root->val < prev->val)
            {
                // mistake detected
                if (mistakes == 0)
                {
                    first = prev;
                    second = root;
                    mistakes++;
                }
                else
                {
                    second = root;
                    mistakes++;
                }
            }
            prev = root;
        }
        solve(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        solve(root);
        swap(first->val, second->val);
    }
};