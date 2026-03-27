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
    void solve(TreeNode* root, vector<int>& arr) {
        if (root == nullptr)
            return;
        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
    }
    bool checkSorted(vector<int> arr) {
        if(arr.size() == 1) return true;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1])
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        solve(root, arr);
        return checkSorted(arr);
    }
};
///////////////////Optimal Solution///////////////////////////////
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
    bool ans = true;
    TreeNode* prev = nullptr;
    void solve(TreeNode* root){
        if(root == nullptr) return;
        solve(root->left);
        if(!prev){
            prev = root;
        }else{
            if(root->val <= prev->val){
                ans = false;
                return;
            }
            prev = root;
        }
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
///////////Most Optimal///////////////////
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
    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
               if(root == nullptr) return true;
        bool leftAns = isValidBST(root->left);
        if(!prev){
            prev = root;
        }else{
            if(root->val <= prev->val){
                return false;
            }
            prev = root;
        }
        bool rightAns = isValidBST(root->right);
        return leftAns && rightAns;
    }
};