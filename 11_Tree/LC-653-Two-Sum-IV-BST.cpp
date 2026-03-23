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
#define node TreeNode
#define null nullptr
class Solution {
public:
    void func(node* root, stack<node*>& asc, vector<int>& res) {
        node* t = root;
        while (t) {
            asc.push(t);
            t = t->left;
        }
        while (!asc.empty()) {
            node* small = asc.top();
            asc.pop();
            res.push_back(small->val);
            node* rightchild = small->right;
            while (rightchild) {
                asc.push(rightchild);
                rightchild = rightchild->left;
            }
        }
    }
    bool findTarget(TreeNode* root, int k) {
        stack<node*> asc;
        vector<int> res;
        func(root, asc, res);
        int start = 0;
        int end = res.size() - 1;
        while (start < end) {
           int sum = res[start]+res[end];
           if(sum == k) return true;
           else if(sum<k) start++;
           else end--;
    }
    return false;
}
}
