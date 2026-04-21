class Solution {
public:
    int rec(int i, int j) {
        //TC -> O(2^(mn))
        //SC -> O(path length)
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        int right = rec(i, j - 1);
        int down = rec(i - 1, j);

        return right + down;
    }
    int mem(int i, int j, vector<vector<int>>& dp) {
        //TC -> O(mn)
        //SC -> O(mn)       
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int left = mem(i, j - 1, dp);
        int up = mem(i - 1, j, dp);

        return dp[i][j] = (left + up);
    }
    int tab(int m, int n) {
        //TC -> O(mn)
        //SC -> O(mn)  
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0){
                    dp[0][0] = 1;
                    continue;
                }
                int left = 0, up = 0;
                if (i > 0) {
                    up = dp[i - 1][j];
                }
                if (j > 0) {
                    left = dp[i][j - 1];
                }
                dp[i][j] = left + up;
            }
        }

        return dp[m - 1][n - 1];
    }
    int so(int m, int n) {
        //TC -> O(mn)
        //SC -> O(n)  
        vector<int> prev(n,0),curr(n,0);
        curr[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i==0&&j==0){
                    continue;
                }
                int up = prev[j];
                int left = 0;
                if(j>0) left = curr[j - 1];
                curr[j] = left + up;
            }
            prev = curr;
        }

        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        int ans;
        // ans = rec(m-1,n-1);
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // ans = mem(m-1,n-1,dp);
        // ans = tab(m, n);
        ans = so(m, n);

        return ans;
    }
};