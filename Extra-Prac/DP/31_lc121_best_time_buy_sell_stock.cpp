class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int lowestbuy = prices[0];
        int n = prices.size();
        for( int i = 1;i<n;i++){
            if(prices[i]>lowestbuy){
                maxprofit = max(maxprofit,prices[i]-lowestbuy);
            }else{
                lowestbuy = prices[i];
            }
        }
        return maxprofit;
    }
};
//TC->O(n)
//SC->O(1)