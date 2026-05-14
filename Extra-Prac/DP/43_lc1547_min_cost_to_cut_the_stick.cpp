class Solution {
public:
    int rec(int i, int j, vector<int>& cuts) {
        if (i > j)
            return 0;
        int mini = 1e9;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j + 1] - cuts[i - 1] + rec(i, ind - 1, cuts) +
                       rec(ind + 1, j, cuts);
            mini = min(cost, mini);
        }
        return mini;
    }
    int mem(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j + 1] - cuts[i - 1] + mem(i, ind - 1, cuts, dp) +
                       mem(ind + 1, j, cuts, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }
    int tab(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));
        for (int i = c - 2; i >= 1; i--) {
            for (int j = 1; j <= c - 2; j++) {
                if (i > j)
                    continue;
                int mini = 1e9;
                for (int ind = i; ind <= j; ind++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] +dp[ind + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c - 2];
    }
    int minCost(int n, vector<int>& cuts) {
        int ans = 0;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();

        // RECURSION
        //  ans = rec(1,c-2,cuts);

        // MEMOIZATON
        //  vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        //  ans = mem(1,c-2,cuts,dp);

        // TABULATION
        ans = tab(n, cuts);

        return ans;
    }
};