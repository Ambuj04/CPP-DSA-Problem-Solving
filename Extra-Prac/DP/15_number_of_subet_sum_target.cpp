class Solution
{
public:
    int rec(int ind, int target, vector<int> &a)
    {
        if (ind == 0)
        {
            if (target == 0 && a[0] == 0)
                return 2; // pick and not pick
            if (target == 0 || target == a[0])
                return 1;
            return 0;
        }
        int inclusive = 0;
        if (a[ind] <= target)
        {
            inclusive = rec(ind - 1, target - a[ind], a);
        }
        int exclusive = rec(ind - 1, target, a);
        return inclusive + exclusive;
    }
    int mem(int ind, int target, vector<int> &a, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && a[0] == 0)
                return 2; // pick or not pick
            if (target == 0 || target == a[0])
                return 1;
            return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int inclusive = 0;
        if (a[ind] <= target)
        {
            inclusive = mem(ind - 1, target - a[ind], a, dp);
        }
        int exclusive = mem(ind - 1, target, a, dp);
        return dp[ind][target] = inclusive + exclusive;
    }
    int tab(int n, int target, vector<int> &a)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // base case
        if (a[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }
        if (a[0] != 0 && a[0] <= target)
        {
            dp[0][a[0]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int inclusive = 0;
                if (a[i] <= tar)
                {
                    inclusive = dp[i - 1][tar - a[i]];
                }
                int exclusive = dp[i - 1][tar];
                dp[i][tar] = (inclusive + exclusive);
            }
        }
        return dp[n - 1][target];
    }
    int so(int n, int target, vector<int> &a)
    {
        vector<int> prev(target + 1), curr(target + 1);
        // base case
        if (a[0] == 0)
        {
            prev[0] = 2;
        }
        else
        {
            prev[0] = 1;
        }
        if (a[0] != 0 && a[0] <= target)
        {
            prev[a[0]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int inclusive = 0;
                if (a[i] <= tar)
                {
                    inclusive = prev[tar - a[i]];
                }
                int exclusive = prev[tar];
                curr[tar] = (inclusive + exclusive);
            }
            prev = curr;
        }
        return prev[target];
    }
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int ans = 0;
        // recursion
        // ans = rec(n-1,target,arr);
        // memoization
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // ans = mem(n - 1, target, arr, dp);
        // tabulation
        // ans = tab(n, target, arr);
        // space optimization
        ans = so(n, target, arr);
        return ans;
    }
};