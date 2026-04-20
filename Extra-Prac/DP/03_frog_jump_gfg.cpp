class Solution
{
public:
    int rec(int idx, vector<int> &height)
    {
        // TC->O(n) + O(n/2)
        // SC->O(n)
        if (idx == 0)
            return 0;
        int first = rec(idx - 1, height) + abs(height[idx] - height[idx - 1]);
        int second = INT_MAX;
        if (idx > 1)
            second = rec(idx - 2, height) + abs(height[idx] - height[idx - 2]);
        return min(first, second);
    }
    int mem(int idx, vector<int> &height, vector<int> &dp)
    {
        // TC->O(n)
        // SC->O(n)
        if (idx == 0)
            return 0;
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        int first = mem(idx - 1, height, dp) + abs(height[idx] - height[idx - 1]);
        int second = INT_MAX;
        if (idx > 1)
            second = mem(idx - 2, height, dp) + abs(height[idx] - height[idx - 2]);
        return dp[idx] = min(first, second);
    }
    int tab(vector<int> &height)
    {
        // TC->O(n)
        // SC->O(n)
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int first = dp[i - 1] + abs(height[i] - height[i - 1]);
            int second = INT_MAX;
            if (i > 1)
                second = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(first, second);
        }
        return dp[n - 1];
    }
    int so(vector<int> &height)
    {
        // TC->O(n)
        // SC->O(1)
        int n = height.size();
        int prev, curr, prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int first = prev + abs(height[i] - height[i - 1]);
            int second = INT_MAX;
            if (i > 1)
                second = prev2 + abs(height[i] - height[i - 2]);
            curr = min(first, second);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int minCost(vector<int> &height)
    {
        int ans;
        int n = height.size();
        // ans = rec(n-1,height);
        vector<int> dp(n, -1);
        // ans = mem(n-1,height,dp);
        // ans = tab(height);
        ans = so(height);
        return ans;
    }
};