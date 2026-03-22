/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define node TreeNode
#define null nullptr
#define data val
class Solution {
public:
    node* ans = null;
    void func(node* root, node* p, node* q) {
        if (root == null)
            return;
        if (root == p or root == q) {
            ans = root;
            return;
        }
        if (root->data < p->data) {
            func(root->right, p, q);
        } else if (root->data > q->data) {
            func(root->left, p, q);
        } else {
            ans = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->data < q->data){
            func(root,p,q);
        }else{
            func(root,q,p);
        }
        return ans;
    }
};
