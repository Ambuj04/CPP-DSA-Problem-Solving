// User function template for C++
class Solution
{
public:
    int rec(int idx, vector<int> &arr)
    {
        if (idx == 0)
            return arr[idx]; // because you can't pick 1 so you will pick 0
        if (idx < 0)
            return 0;
        int include = arr[idx] + rec(idx - 2, arr); //-1 in general, but -2 for non adjancent
        int exclude = rec(idx - 1, arr);            // exclude adjacent element
        return max(include, exclude);
    }
    int mem(int idx, vector<int> &arr, vector<int> &dp)
    {
        if (idx == 0)
            return arr[idx];
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int include = arr[idx] + mem(idx - 2, arr, dp);
        int exclude = mem(idx - 1, arr, dp);
        return dp[idx] = max(include, exclude);
    }
    int tab(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            int include = arr[i]; // eye
            if (i > 1)
            {
                include += dp[i - 2];
            }
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        return dp[n - 1];
    }
    int so(vector<int> &arr)
    {
        int n = arr.size();
        int prev2 = 0;
        int prev = arr[0];
        int curr;
        for (int i = 1; i < n; i++)
        {
            int include = arr[i] + prev2;
            int exclude = prev;
            curr = max(include, exclude);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        int ans;
        //   ans = rec(n-1,arr);//in recursion always check for outofbound
        vector<int> dp(n, -1);
        //   ans = mem(n-1,arr,dp);
        // ans = tab(arr);
        ans = so(arr);
        return ans;
    }
};