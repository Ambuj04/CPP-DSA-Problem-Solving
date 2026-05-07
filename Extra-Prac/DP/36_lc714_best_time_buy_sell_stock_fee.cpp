#define ll long long
class Solution {
public: 
    //Best time to buy and sell stock with unlimited times
    int so1(vector<int>&prices,int fee){
        int n = prices.size();
        ll prev0 = 0,prev1 = 0,curr0 = 0,curr1 = 0;   
        //base case for ind == n (omit because it is already zero)
        for(int ind = n-1;ind>=0;ind--){
            //buy = 1
            ll take = - prices[ind]+ prev0;
            ll nottake = prev1;
            curr1 = max(take,nottake);
            //buy = 0
            ll sell = prices[ind] - fee + prev1;
            ll notsell = prev0;
            curr0 = max(sell,notsell);
            prev0 = curr0;
            prev1 = curr1;
        }
        return prev1;
    }
    int maxProfit(vector<int>& prices, int fee) {
        return so1(prices,fee);
        
    }
};