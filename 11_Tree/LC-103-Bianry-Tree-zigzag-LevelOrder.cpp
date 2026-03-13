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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        bool leftToright = true;
        int low,high;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int>temp(levelSize);
            low = 0;
            high = levelSize-1;
            while (levelSize--) {
                TreeNode* t = q.front();
                if(leftToright){

                temp[low] = (t->val);
                low++;
                }else{
                    temp[high] = t->val;
                    high--;
                }
                q.pop();
                if (t->left != nullptr) {
                    q.push(t->left);
                }
                if (t->right != nullptr) {
                    q.push(t->right);
                }
            }
                leftToright = !leftToright;
                res.push_back(temp);
        }
        return res;
    }
};