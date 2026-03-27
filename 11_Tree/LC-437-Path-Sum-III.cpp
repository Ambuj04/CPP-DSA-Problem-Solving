//my brute force   O(n^2) TC
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
    int numberOfPaths(TreeNode* root, int targetSum, long long sum) {
        if (root == nullptr) {
            return 0;
        }
        sum += root->val;
        int count = 0;
        if (sum == targetSum) {
            count++;
        }
        int leftside  = numberOfPaths(root->left, targetSum, sum);
        int rightside =   numberOfPaths(root->right, targetSum, sum);
        int total = count + leftside + rightside;
        return total;
    }
    int traverseNode(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        long long sum = 0;
        return numberOfPaths(root, targetSum, sum) +
               traverseNode(root->left, targetSum) +
               traverseNode(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        return traverseNode(root, targetSum);
    }
};
//////////////////////////////////////////////////////////////
/* Optimal Solution  */
class Solution {
public:
    int dfs(TreeNode* root, long currentSum, int target, unordered_map<long,int>& mp) {
        if (!root) return 0;
        currentSum += root->val;
        int count = 0;
        if (mp.find(currentSum - target) != mp.end()) {
            count += mp[currentSum - target];
        }
        mp[currentSum]++;
        count += dfs(root->left, currentSum, target, mp);
        count += dfs(root->right, currentSum, target, mp);
        mp[currentSum]--; // backtrack
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int> mp;
        mp[0] = 1; // important
        return dfs(root, 0, targetSum, mp);
    }
};