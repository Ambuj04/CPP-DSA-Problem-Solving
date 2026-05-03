class Solution {
  public:
   int rec(int ind, int target, vector<int>& a) {
        // base case
        if (ind == 0) {
            if (target % a[0] == 0) {
                return 1;
            }
            return 0;
        }
        // recursive relation
        int exclusive = rec(ind - 1, target, a);
        int inclusive = 0;
        if (a[ind] <= target) {
            inclusive = rec(ind, target - a[ind], a); // infinite supply
        }
        return inclusive + exclusive;
    }
    int mem(int ind, int target, vector<int>& a, vector<vector<int>>& dp) {
        // base case
        if (ind == 0) {
            if (target % a[0] == 0) {
                return 1;
            }
            return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        // recursive relation
        int exclusive = mem(ind - 1, target, a, dp);
        int inclusive = 0;
        if (a[ind] <= target) {
            inclusive = mem(ind, target - a[ind], a, dp); // infinite supply
        }
        return dp[ind][target] = (inclusive + exclusive);
    }

    int tab(int n, int target, vector<int>& a) {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // base case
        for (int tar = 0; tar <= target; tar++) {
            dp[0][tar] = (tar % a[0] == 0);
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                // recursive relation
                int exclusive = dp[ind - 1][tar];
                int inclusive = 0;
                if (a[ind] <= tar) {
                    inclusive = dp[ind][tar - a[ind]]; // infinite supply
                }
                dp[ind][tar] = (inclusive + exclusive);
            }
        }
        return dp[n - 1][target];
    }

    int so(int n, int target, vector<int>& a) {
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        // base case
        for (int tar = 0; tar <= target; tar++) {
            if (tar % a[0] == 0) {
                prev[tar] = 1;
            } else {
                prev[tar] = 0;
            }
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                // recursive relation
                int exclusive = prev[tar];
                int inclusive = 0;
                if (a[ind] <= tar) {
                    inclusive = curr[tar - a[ind]]; // infinite supply
                }
                curr[tar] = (inclusive + exclusive);
            }
            prev = curr;
        }
        return prev[target];
    }
    int count(vector<int>& coins, int sum) {
        int ans;
        int n = coins.size();

        // RECURSION
        //  ans = rec(n - 1, sum, coins);

        // MEMOIZATION
        //  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        //  ans = mem(n - 1, sum, coins, dp);

        // TABULATION
        // ans = tab(n, sum, coins);

        // SPACE OPTIMIZATION
         ans = so(n,sum,coins);

        return ans;
        
    }
};