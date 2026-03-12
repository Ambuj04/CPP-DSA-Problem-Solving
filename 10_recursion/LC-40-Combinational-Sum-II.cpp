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

            // prevents from duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);
            // travel choices by i
            solve(i + 1, n, target - candidates[i], temp, candidates, res);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int index = 0;
        int n = candidates.size();
        sort(candidates.begin(),
             candidates.end()); // may contains duplicate elements
        vector<int> temp;
        vector<vector<int>> res;
        solve(index, n, target, temp, candidates, res);
        return res;
    }
};