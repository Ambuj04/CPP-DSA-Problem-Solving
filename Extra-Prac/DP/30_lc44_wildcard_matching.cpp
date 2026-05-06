class Solution {
public:
    bool rec(int i, int j, string& p, string& s) {
        // both exhausted
        if (i < 0 && j < 0)
            return true;

        // pattern exhausted but string remains
        if (i < 0 && j >= 0)
            return false;

        // string exhausted
        if (j < 0 && i >= 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // match or '?'
        if (p[i] == s[j] || p[i] == '?') {
            return rec(i - 1, j - 1, p, s);
        }

        // '*'
        if (p[i] == '*') {
            return rec(i - 1, j, p, s)     // '*' = empty
                   || rec(i, j - 1, p, s); // '*' = consume char
        }

        return false;
    }
    bool mem(int i, int j, string& p, string& s, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = mem(i - 1, j - 1, p, s, dp);
        }

        if (p[i] == '*') {
            return dp[i][j] =
                       mem(i - 1, j, p, s, dp) || mem(i, j - 1, p, s, dp);
        }

        return dp[i][j] = false;
    }
    bool mem1(int i, int j, string& p, string& s, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return true;
        if (i == 0 && j > 0)
            return false;
        if (j == 0 && i > 0) {
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
            return dp[i][j] = mem1(i - 1, j - 1, p, s, dp);
        }

        if (p[i - 1] == '*') {
            return dp[i][j] =
                       mem1(i - 1, j, p, s, dp) || mem1(i, j - 1, p, s, dp);
        }

        return dp[i][j] = false;
    }
    bool tab(int n, int m, string& p, string& s) {
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
            dp[0][j] = false;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    } 
    bool so(int n, int m, string& p, string& s) {
        vector<bool> prev(m + 1,false),curr(m+1,false);
        prev[0] = true;
        for (int j = 1; j <= m; j++)
            prev[j] = false;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    curr[j] = prev[j-1];
                } else if (p[i - 1] == '*') {
                    curr[j] = prev[j] || curr[j-1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    } 
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        bool ans = false;

        // RECURSION
        //  ans = rec(n-1,m-1,p,s);

        // MEMOIZATOIN
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // ans = mem(n-1,m-1,p,s,dp);

        // MEMOIZATOIN 1 BASED
        //  vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //  ans = mem1(n,m,p,s,dp);
        //  return ans;

        // TABULAITON
        // ans = tab(n, m, p, s);

        //SPACE OPTIMIZATION
        ans = so(n,m,p,s);

        return ans;
    }
};