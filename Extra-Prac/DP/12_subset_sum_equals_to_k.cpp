class Solution
{
public:
    bool rec(int ind, int target, vector<int> &a)
    {
        //(tc O(2^n),sc O(n))
        if (target == 0)
            return true;
        if (ind == 0)
            return a[0] == target;
        bool inclusive = rec(ind - 1, target - a[ind], a);
        bool exclusive = rec(ind - 1, target, a);
        return inclusive || exclusive;
    }
    bool mem(int ind, int target, vector<int> &a, vector<vector<int>> &dp)
    { //tc O(n*target),sc O(n*target + O(n)))
        if (target == 0)
            return true;
        if (ind == 0)
            return a[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool inclusive = false;
        if (a[ind] <= target)
            inclusive = mem(ind - 1, target - a[ind], a, dp);
        bool exclusive = mem(ind - 1, target, a, dp);
        return dp[ind][target] = inclusive || exclusive;
    }
    bool tab(int n, int target, vector<int> &a)
    {
        //(tc O(n*target),sc O(n*target)
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (a[0] <= target)
            dp[0][a[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int i = 1; i <= target; i++)
            {
                bool inclusive = false;
                if (a[ind] <= i)
                    inclusive = dp[ind - 1][i - a[ind]];
                bool exclusive = dp[ind - 1][i];
                dp[ind][i] = inclusive || exclusive;
            }
        }
        return dp[n - 1][target];
    }
    bool so(int n, int target, vector<int> &a)
    {
        //(tc O(n*target),sc O(target)
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        prev[0] = true;
        if (a[0] <= target)
            prev[a[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            curr[0] = true; // IMPORTANT
            for (int i = 1; i <= target; i++)
            {
                bool inclusive = false;
                if (a[ind] <= i)
                    inclusive = prev[i - a[ind]];
                bool exclusive = prev[i];
                curr[i] = inclusive || exclusive;
            }
            prev = curr;
        }
        return prev[target];
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        bool ans;
        // RECURSION
        // ans = rec(n-1,sum,arr);
        // MEMOIZATION
        //  vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        //  ans = mem(n-1,sum,arr,dp);
        // TABULATION
        // ans = tab(n, sum, arr);
        // SPACE OPTIMIZATION
        ans = so(n, sum, arr);
        return ans;
    }
};