class Solution {
public:
    void solve(int index, int n, int target, vector<int>& temp,
               vector<int>& candidates, vector<vector<int>>& res) {
        // base case
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (target < 0) {
            return;
        }
        // travel stages by index
        for (int i = index; i < n; i++) {
            temp.push_back(candidates[i]);
            // travel choices by i
            solve(i, n, target - candidates[i], temp, candidates, res);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index = 0;
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> res;
        solve(index, n, target, temp, candidates, res);
        return res;
    }
};