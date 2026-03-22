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
public:
#define node TreeNode
#define null nullptr
    int solve(node* root, node* p, node* q, node*& ans, bool& first) {
        if (root == null)
            return 0;
        int leftMeKitneKeBoss = solve(root->left, p, q, ans, first);
        int rightMeKitneKeBoss = solve(root->right, p, q, ans, first);
        int khudKeBoss = 0;
        if (root == p || root == q)
            khudKeBoss++;
        int total = leftMeKitneKeBoss + rightMeKitneKeBoss + khudKeBoss;
        if (total == 2 && first == false) {
            ans = root;
            first = true;
        }
        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        node* ans = null;
        bool first = false;
        solve(root, p, q, ans, first);
        return ans;
    }
};