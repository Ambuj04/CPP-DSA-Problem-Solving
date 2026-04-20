#include <bits/stdc++.h>
using namespace std;

// 1. Pure Recursion
int rec(int idx, vector<int> &heights, int k)
{
    if (idx == 0)
        return 0;
    int mini = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (idx - j >= 0)
        {
            int jump = rec(idx - j, heights, k) + abs(heights[idx] - heights[idx - j]);
            mini = min(mini, jump);
        }
    }
    return mini;
}
// 2. Memoization
int mem(int idx, vector<int> &heights, int k, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int mini = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (idx - j >= 0)
        {
            int jump = mem(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx - j]);
            mini = min(mini, jump);
        }
    }
    return dp[idx] = mini;
}

//3. Tabulation
int tab(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                mini = min(mini, jump);
            }
        }
        dp[i] = mini;
    }
    return dp[n - 1];
}
int main()
{
    vector<int> height{15, 4, 1, 14, 15};
    int k = 3;
    int n = height.size();
    cout << "Recursion: " << rec(n - 1, height, k) << endl;
    vector<int> dp(n, -1);
    cout << "Memoization: " <<mem(n - 1, height, k, dp) << endl;
    cout << "Tabulation: " << tab(height,k) << endl;
    return 0;
}