/*
Shortcut trick--------------------------
step 1: try to represent the problem in terms of index
step 2: do all possible stuffs on that index according to problem
step 3: sum of all stuffs -> count all way
step 4:if n-1 n-2 then always space optimization
min of all stuffs -> min of all way
*/
class Solution
{
public:
    int rec(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        int byone = rec(n - 1);
        int bytwo = rec(n - 2);
        return (byone + bytwo);
    }
    int mem(int n, vector<int> &dp)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = mem(n - 1, dp) + mem(n - 2, dp);
    }
    int tab(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int so(int n)
    {
        int prev2 = 1;
        int prev = 1;
        int curr;
        for (int i = 2; i <= n; i++)
        {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int climbStairs(int n)
    {
        // return rec(n);
        vector<int> dp(n + 1, -1);
        // return mem(n,dp);
        // return tab(n);
        return so(n);
    }
};