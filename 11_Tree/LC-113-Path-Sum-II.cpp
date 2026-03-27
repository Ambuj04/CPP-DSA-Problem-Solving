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
    void solve(TreeNode* root,int targetSum,int sum,vector<int>&temp,vector<vector<int>>&res){
        if(root == nullptr) return;
        temp.push_back(root->val);
        sum += root->val;
        //leaf node
        if(root->left == nullptr && root->right == nullptr && sum == targetSum){
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        solve(root->left,targetSum,sum,temp,res);
        solve(root->right,targetSum,sum,temp,res);
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        vector<vector<int>>res;
        solve(root,targetSum,0,temp,res);
        return res;
        
    }
};