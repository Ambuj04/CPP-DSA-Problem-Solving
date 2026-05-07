class Solution {
public:
    int rec(int ind, int trans, int& n, int& k, vector<int>& prices) {
        if (ind == n || trans == 2 * k) {
            return 0;
        }
        if (trans % 2 == 0) {
            // buy = 1
            int take = -prices[ind] + rec(ind + 1, trans + 1, n, k, prices);
            int nottake = rec(ind + 1, trans, n, k, prices);
            return max(take, nottake);
        } else {
            // buy = 0
            int sell = prices[ind] + rec(ind + 1, trans + 1, n, k, prices);
            int notsell = rec(ind + 1, trans, n, k, prices);
            return max(sell, notsell);
        }
    }
    int mem(int ind, int trans, int& n, int& k, vector<int>& prices,
            vector<vector<int>>& dp) {
        if (ind == n || trans == 2 * k) {
            return 0;
        }
        if (dp[ind][trans] != -1)
            return dp[ind][trans];
        if (trans % 2 == 0) {
            // buy = 1
            int take = -prices[ind] + mem(ind + 1, trans + 1, n, k, prices, dp);
            int nottake = mem(ind + 1, trans, n, k, prices, dp);
            return dp[ind][trans] = max(take, nottake);
        } else {
            // buy = 0
            int sell = prices[ind] + mem(ind + 1, trans + 1, n, k, prices, dp);
            int notsell = mem(ind + 1, trans, n, k, prices, dp);
            return dp[ind][trans] = max(sell, notsell);
        }
    }
    int tab(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    // buy = 1
                    int take = -prices[ind] +
                               dp[ind + 1][trans + 1];
                    int nottake = dp[ind + 1][trans];
                    dp[ind][trans] = max(take, nottake);
                } else {
                    // buy = 0
                    int sell =
                        prices[ind] + dp[ind + 1][trans + 1];
                    int notsell = dp[ind + 1][trans];
                    dp[ind][trans] = max(sell, notsell);
                }
            }
        }
        return dp[0][0];
    }
    int so(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2*k + 1, 0),curr(2*k + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {
                if (trans % 2 == 0) {
                    // buy = 1
                    int take = -prices[ind] +
                               prev[trans + 1];
                    int nottake = prev[trans];
                    curr[trans] = max(take, nottake);
                } else {
                    // buy = 0
                    int sell =
                        prices[ind] + prev[trans + 1];
                    int notsell = prev[trans];
                    curr[trans] = max(sell, notsell);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        // RECURSION
        //  ans = rec(0,0,n,k,prices);

        // MEMOIZATION
        // vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        // ans = mem(0, 0, n, k, prices, dp);

        // TABULATION
        // ans = tab(k, prices);

        //SAPCE OPTIMIZATON
        ans = so(k,prices);

        return ans;
    }
};