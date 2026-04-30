class Solution {
  public:
  int rec(int ind,int W,vector<int>&val,vector<int>&wt){
      //TC O(2^n)
      //SC O(n)
      //base case
      if(ind == 0){
          if(wt[ind]<=W){
              return val[ind];
          }
          return 0;
      }
      //recursion
      int inclusive = INT_MIN;
      if(wt[ind]<=W){
          inclusive = val[ind] + rec(ind-1,W-wt[ind],val,wt);
      }
      int exclusive = rec(ind-1,W,val,wt);
      return max(inclusive,exclusive);
  }
  int mem(int ind,int W,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
      //TC O(W*n) 
      //SC O(W*n + n)
      //base case
      if(ind == 0){
          if(wt[ind]<=W){
              return val[ind];
          }
          return 0;
      }
      if(dp[ind][W]!=-1) return dp[ind][W];
      //recursion
      int inclusive = INT_MIN;
      if(wt[ind]<=W){
          inclusive = val[ind] + mem(ind-1,W-wt[ind],val,wt,dp);
      }
      int exclusive = mem(ind-1,W,val,wt,dp);
      return dp[ind][W] = max(inclusive,exclusive);
  }
    int tab(int W, vector<int> &val, vector<int> &wt) {
      //TC O(W*n) 
      //SC O(W*n)
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0)); 
        //base case
        for(int i = wt[0];i<=W;i++){
            dp[0][i] = val[0];
        }
        //nested loop
        for(int ind = 1;ind<n;ind++){
            for(int w = 0;w<=W;w++){ 
                  int inclusive = INT_MIN;
                        if (wt[ind] <= w) {
                            inclusive = val[ind] + dp[ind-1][w - wt[ind]];
                        }
                  int exclusive = dp[ind-1][w];
                  dp[ind][w] = max(inclusive,exclusive);                
            }
        }
        return dp[n-1][W];
    }
    int so1(int W, vector<int> &val, vector<int> &wt) {
      //TC O(W*n) 
      //SC O(2n)
        int n = val.size();
        vector<int> prev(W+1,0),curr(W+1,0);
        //base case
        for(int i = wt[0];i<=W;i++){
            prev[i] = val[0];
        }
        //nested loop
        for(int ind = 1;ind<n;ind++){
            for(int w = 0;w<=W;w++){ 
                  int inclusive = INT_MIN;
                        if (wt[ind] <= w) {
                            inclusive = val[ind] + prev[w - wt[ind]];
                        }
                  int exclusive = prev[w];
                  curr[w] = max(inclusive,exclusive);                
            }
            prev = curr;
        }
        return prev[W];
    }
    int so2(int W, vector<int> &val, vector<int> &wt) {
      //TC O(W*n) 
      //SC O(n)
        int n = val.size();
        vector<int> prev(W+1,0);
        //base case
        for(int i = wt[0];i<=W;i++){
            prev[i] = val[0];
        }
        //nested loop
        for(int ind = 1;ind<n;ind++){
            for(int w = W;w>=0;w--){ 
                  int inclusive = INT_MIN;
                        if (wt[ind] <= w) {
                            inclusive = val[ind] + prev[w - wt[ind]];
                        }
                  int exclusive = prev[w];
                  prev[w] = max(inclusive,exclusive);                
            }
        }
        return prev[W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int ans = 0;
        int n = val.size();
        //RECURSION
        // ans = rec(n-1,W,val,wt);
        //MEMOIZATION
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));   
        // ans = mem(n-1,W,val,wt,dp);
        //TABULATION(BOTTOM UP APPROACH)
        // ans = tab(W,val,wt);
        //SPACE OPTIMIZATION
        // ans = so1(W,val,wt);
        ans = so2(W,val,wt);
        return ans;
    }
};