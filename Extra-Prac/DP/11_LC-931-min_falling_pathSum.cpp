class Solution {
public:
    int rec(int i, int j, int n, vector<vector<int>>& a) {
        if (j < 0 || j > (n - 1)) {
            return 10e7; // 100000000
        }
        if (i == 0)
            return a[0][j];
        int straight = a[i][j] + rec(i - 1, j, n, a);
        int leftd = a[i][j] + rec(i - 1, j - 1, n, a);
        int rightd = a[i][j] + rec(i - 1, j + 1, n, a);
        return min(straight, min(leftd, rightd));
    }
    int mem(int i, int j, int n, vector<vector<int>>& a,
            vector<vector<int>>& dp) {
        if (j < 0 || j > (n - 1)) {
            return 10e6; // 10000000
        }
        if (i == 0)
            return a[0][j];
        if (dp[i][j] != 10e6)
            return dp[i][j];
        int straight = a[i][j] + mem(i - 1, j, n, a, dp);
        int leftd = a[i][j] + mem(i - 1, j - 1, n, a, dp);
        int rightd = a[i][j] + mem(i - 1, j + 1, n, a, dp);
        return dp[i][j] = min(straight, min(leftd, rightd));
    }
    int tab(vector<vector<int>>& a, int n) {
        vector<vector<int>> dp(n, vector<int>(n, 10e6));
        for (int j = 0; j < n; j++) {
            dp[0][j] = a[0][j]; // base case
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int straight = a[i][j] + dp[i - 1][j];
                int leftd = INT_MAX, rightd = INT_MAX;
                if (j - 1 >= 0)
                    leftd = a[i][j] + dp[i - 1][j - 1];
                if (j + 1 < n)
                    rightd = a[i][j] + dp[i - 1][j + 1];
                dp[i][j] = min(straight, min(leftd, rightd));
            }
        }
        int mini = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
    int so(vector<vector<int>>& a, int n) {
        vector<int> prev(n), curr(n);
        for (int j = 0; j < n; j++) {
            prev[j] = a[0][j]; // base case
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int straight = a[i][j] + prev[j];
                int leftd = INT_MAX, rightd = INT_MAX;
                if (j - 1 >= 0)
                    leftd = a[i][j] + prev[j - 1];
                if (j + 1 < n)
                    rightd = a[i][j] + prev[j + 1];
                curr[j] = min(straight, min(leftd, rightd));
            }
            prev = curr;
        }
        int mini = prev[0];
        for (int j = 1; j < n; j++) {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int temp;
        int n = matrix.size();
        int mini = INT_MAX;
        // recursion
        /*
               for (int i = n - 1; i >= 0; i--) {
                   temp = rec(n - 1, i, n, matrix);
                   mini = min(mini, temp);
               }
       */
        // memorization
        /*
         vector<vector<int>> dp(n, vector<int>(n, 10e6));
         for (int i = n - 1; i >= 0; i--) {
             temp = mem(n - 1, i, n, matrix, dp);
             mini = min(mini, temp);
         }
         */
        // tabulation
        /*
                mini = tab(matrix, n);
        */
        // space optimization
        mini = so(matrix, n);
        return mini;
    }
};