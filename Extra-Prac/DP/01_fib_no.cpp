#include <bits/stdc++.h>
using namespace std;
int mem(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = mem(n - 1, dp) + mem(n - 2, dp);
    // TC O(n) -> linear pattern
    // SC O(n) + O(n)  stack space and array
}
int tab(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
    // TC O(n) -> linear pattern
    // SC O(n)  -> dp array
}
int so(int n)
{
   
    int prev2 = 0;
    int prev1 = 1;
    int curr ;
    for (int i = 2; i <= n; i++)
    {
       curr = prev1+prev2;
       prev2 = prev1;
       prev1 = curr;
       
    }
    return prev1;
    // TC O(n) -> linear pattern
    // SC O(1)  -> fix variable
}
int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << mem(n, dp); // memorization
    cout << tab(n);     // tabulation
    cout << so(n);      // space optimation
    return 0;
}
