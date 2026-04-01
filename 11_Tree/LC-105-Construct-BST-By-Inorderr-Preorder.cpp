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
public:
    unordered_map<int,int>inMap;
    int idx = 0;
    TreeNode* solve(vector<int>&preorder,int low,int high){
        if(high < low) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        int id = inMap[root->val];
        idx++;
        root->left = solve(preorder,low,id-1);
        root->right = solve(preorder,id+1,high);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
       for(int i = 0 ; i < n;i++){
        inMap[inorder[i]] = i;
       }
        return solve(preorder,0,n-1);
    }
};