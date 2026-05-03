class Solution {
public:
    int rec(int ind, int target, vector<int>& a) {
        // base case
        if (ind == 0) {
            if (target % a[0] == 0) {
                return target / a[0];
            }
            return 1e9;
        }
        // recursive relation
        int exclusive = rec(ind - 1, target, a);
        int inclusive = 1e9;
        if (a[ind] <= target) {
            inclusive = 1 + rec(ind, target - a[ind], a); // infinite supply
        }
        return min(inclusive, exclusive);
    }
    int mem(int ind, int target, vector<int>& a, vector<vector<int>>& dp) {
        // base case
        if (ind == 0) {
            if (target % a[0] == 0) {
                return target / a[0];
            }
            return 1e9;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        // recursive relation
        int exclusive = mem(ind - 1, target, a, dp);
        int inclusive = 1e9;
        if (a[ind] <= target) {
            inclusive = 1 + mem(ind, target - a[ind], a, dp); // infinite supply
        }
        return dp[ind][target] = min(inclusive, exclusive);
    }
    int tab(int n, int target, vector<int>& a) {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // base case
        for (int tar = 0; tar <= target; tar++) {
            if (tar % a[0] == 0) {
                dp[0][tar] = tar / a[0];
            } else {
                dp[0][tar] = 1e9;
            }
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                // recursive relation
                int exclusive = dp[ind - 1][tar];
                int inclusive = 1e9;
                if (a[ind] <= tar) {
                    inclusive =
                        1 + dp[ind][tar - a[ind]]; // infinite supply
                }
                dp[ind][tar] = min(inclusive, exclusive);
            }
        }
        return dp[n-1][target];
    }
    int so(int n, int target, vector<int>& a) {
        vector<int> prev(target+1,0),curr(target+1,0);
        // base case
        for (int tar = 0; tar <= target; tar++) {
            if (tar % a[0] == 0) {
                prev[tar] = tar / a[0];
            } else {
                prev[tar] = 1e9;
            }
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                // recursive relation
                int exclusive = prev[tar];
                int inclusive = 1e9;
                if (a[ind] <= tar) {
                    inclusive =
                        1 + curr[tar - a[ind]]; // infinite supply
                }
                curr[tar] = min(inclusive, exclusive);
            }
            prev = curr;
        }
        return prev[target];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans;
        int n = coins.size();
        // RECURSION
        //  ans = rec(n - 1, amount, coins);
        // MEMOIZATION
        //  vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        //  ans = mem(n - 1, amount, coins, dp);
        // TABULATION
        // ans = tab(n, amount, coins);
        //SPACE OPTIMIZATION
        ans = so(n,amount,coins);
        if (ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};