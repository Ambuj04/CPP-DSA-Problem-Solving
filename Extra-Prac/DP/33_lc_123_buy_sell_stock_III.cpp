class Solution {
public:
    int rec(int ind, int buy, int cap, int& n, vector<int>& prices) {
        // base case
        if (ind == n || cap == 0) {
            return 0;
        }
        // recurence
        if (buy) {
            int take = -prices[ind] + rec(ind + 1, 0, cap, n, prices);
            int nottake = rec(ind + 1, 1, cap, n, prices);
            return max(take, nottake);
        } else {
            int sell = prices[ind] + rec(ind + 1, 1, cap - 1, n, prices);
            int notsell = rec(ind + 1, 0, cap, n, prices);
            return max(sell, notsell);
        }
    }
    int mem(int ind, int buy, int cap, int& n, vector<int>& prices,
            vector<vector<vector<int>>>& dp) {
        // base case
        if (ind == n || cap == 0) {
            return 0;
        }
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        // recurence
        if (buy) {
            int take = -prices[ind] + mem(ind + 1, 0, cap, n, prices, dp);
            int nottake = mem(ind + 1, 1, cap, n, prices, dp);
            return dp[ind][buy][cap] = max(take, nottake);
        } else {
            int sell = prices[ind] + mem(ind + 1, 1, cap - 1, n, prices, dp);
            int notsell = mem(ind + 1, 0, cap, n, prices, dp);
            return dp[ind][buy][cap] = max(sell, notsell);
        }
    }
    int tab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // in base case we don't do anything because in bc we do 0 but 0 is
        // already in dp
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 2; cap >= 1; cap--) {
                // buy = 1
                int take = -prices[ind] + dp[ind + 1][0][cap];
                int nottake = dp[ind + 1][1][cap];
                dp[ind][1][cap] = max(take, nottake);
                // buy = 0
                int sell = prices[ind] + dp[ind + 1][1][cap - 1];
                int notsell = dp[ind + 1][0][cap];
                dp[ind][0][cap] = max(sell, notsell);
            }
        }
        return dp[0][1][2];
    }
    int so(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0)),curr(2, vector<int>(3, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 2; cap >= 1; cap--) {
                // buy = 1
                int take = -prices[ind] + prev[0][cap];
                int nottake = prev[1][cap];
                curr[1][cap] = max(take, nottake);
                // buy = 0
                int sell = prices[ind] + prev[1][cap - 1];
                int notsell = prev[0][cap];
                curr[0][cap] = max(sell, notsell);
            }
            prev = curr;
        }
        return prev[1][2];
    }
    int so1(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;

        for (int price : prices) {
            buy1 = max(buy1, -price);          // buy first stock
            sell1 = max(sell1, buy1 + price);  // sell first stock
            buy2 = max(buy2, sell1 - price);   // buy second stock
            sell2 = max(sell2, buy2 + price);  // sell second stock
        }
        return sell2;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        // RECURSION
        //  ans = rec(0,1,2,n,prices);

        // MEMOIZATION
        //  vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        //  ans = mem(0,1,2,n,prices,dp);

        // TABULATION
        // ans = tab(prices);

        //SPACE OPTIMIZATION
        // ans = so(prices);

        //Space OPTIMIZATION
        ans = so1(prices);

        return ans;
    }
};