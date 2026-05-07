#define ll long long
class Solution {
public:
//buy and sell stock unlimited times
    int tab(vector<int>&prices){
        int n = prices.size();
        vector<vector<ll>>dp(n+2,vector<ll>(2,0));       
        //base case for ind == n (omit because it is already zero)
        for(int ind = n-1;ind>=0;ind--){
            //buy = 1
            ll take = - prices[ind] + dp[ind+1][0];
            ll nottake = dp[ind+1][1];
            dp[ind][1] = max(take,nottake);
            //buy = 0
            ll sell = prices[ind] + dp[ind+2][1];
            ll notsell = dp[ind+1][0];
            dp[ind][0] = max(sell,notsell);
        }
        return (int)dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        return tab(prices);
        
    }
};