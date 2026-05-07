#define ll long long
class Solution {
public:
    int rec(int ind,int buy,int &n,vector<int>&prices){
        //base case
        if(ind == n){
            return 0;
        }
        //recursive relation
        if(buy){
            int take = -prices[ind] + rec(ind+1,0,n,prices);
            int nottake = rec(ind+1,1,n,prices);
            return max(take,nottake);
        }else{
            int sell = prices[ind] + rec(ind+1,1,n,prices);
            int notsell = rec(ind+1,0,n,prices);
            return max(sell,notsell);
        }
    }
    int mem(int ind,int buy,int &n,vector<int>&prices,vector<vector<int>>&dp){
        //base case
        if(ind == n){
            return 0;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];
        //recursive relation
        if(buy){
            int take = -prices[ind] + mem(ind+1,0,n,prices,dp);
            int nottake = mem(ind+1,1,n,prices,dp);
            return dp[ind][buy] = max(take,nottake);
        }else{
            int sell = prices[ind] + mem(ind+1,1,n,prices,dp);
            int notsell = mem(ind+1,0,n,prices,dp);
            return dp[ind][buy] = max(sell,notsell);
        }
    }
    int tab(vector<int>&prices){
        int n = prices.size();
        vector<vector<ll>>dp(n+1,vector<ll>(2,0));       
        //base case for ind == n (omit because it is already zero)
        for(int ind = n-1;ind>=0;ind--){
            //buy = 1
            ll take = - prices[ind] + dp[ind+1][0];
            ll nottake = dp[ind+1][1];
            dp[ind][1] = max(take,nottake);
            //buy = 0
            ll sell = prices[ind] + dp[ind+1][1];
            ll notsell = dp[ind+1][0];
            dp[ind][0] = max(sell,notsell);
        }
        return (int)dp[0][1];
    }
    int so(vector<int>&prices){
        int n = prices.size();
        vector<ll> prev(2,0),curr(2,0);       
        //base case for ind == n (omit because it is already zero)
        for(int ind = n-1;ind>=0;ind--){
            //buy = 1
            ll take = - prices[ind] + prev[0];
            ll nottake = prev[1];
            curr[1] = max(take,nottake);
            //buy = 0
            ll sell = prices[ind] + prev[1];
            ll notsell = prev[0];
            curr[0] = max(sell,notsell);
            prev = curr;
        }
        return prev[1];
    }
    int so1(vector<int>&prices){
        int n = prices.size();
        ll prev0 = 0,prev1 = 0,curr0 = 0,curr1 = 0;   
        //base case for ind == n (omit because it is already zero)
        for(int ind = n-1;ind>=0;ind--){
            //buy = 1
            ll take = - prices[ind] + prev0;
            ll nottake = prev1;
            curr1 = max(take,nottake);
            //buy = 0
            ll sell = prices[ind] + prev1;
            ll notsell = prev0;
            curr0 = max(sell,notsell);
            prev0 = curr0;
            prev1 = curr1;
        }
        return prev1;
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        
        //RECURSION
        // ans = rec(0,1,n,prices);

        //MEMOIZATION
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // ans = mem(0,1,n,prices,dp);

        //TABULATION
        // ans = tab(prices);

        //SPACE OPTIMIZATION
        // ans = so(prices);
           ans = so1(prices);

        return ans;
    }
};