// User function Template for C++

class Solution {
  public:
    int rec(int ind,int n,vector<int>&a){
        //base case
        if(ind == 0){
            return (n*a[0]);
        }
        //recusive relation
        int notpick = 0 + rec(ind-1,n,a);
        int pick = INT_MIN;
        if(n >= (ind+1)){
            pick = a[ind] + rec(ind,n-(ind+1),a);
        }
        return max(pick,notpick);
    }
    int mem(int ind,int n,vector<int>&a,vector<vector<int>>&dp){
        //base case
        if(ind == 0){
            return (n*a[0]);
        }
        if(dp[ind][n] != - 1) return dp[ind][n];
        //recusive relation
        int notpick = 0 + mem(ind-1,n,a,dp);
        int pick = INT_MIN;
        if(n >= (ind+1)){
            pick = a[ind] + mem(ind,n-(ind+1),a,dp);
        }
        return dp[ind][n] = max(pick,notpick);
    }
    int tab(int n,vector<int>&a){
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        //base case
         for(int i = 0;i<=n;i++){
             dp[0][i] = i*a[0];
         }
         for(int ind = 1;ind<n;ind++){
             for(int N = 0;N<=n;N++){
                 //recusive relation
                    int notpick = 0 + dp[ind-1][N];
                    int pick = INT_MIN;
                    if(N >= (ind+1)){
                        pick = a[ind] + dp[ind][N-(ind+1)];
                    }
                    dp[ind][N] = max(pick,notpick);
             }
         }
        return dp[n-1][n];
    }
    int so(int n,vector<int>&a){
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        vector<int> prev(n+1,0),curr(n+1,0);
        //base case
         for(int i = 0;i<=n;i++){
             prev[i] = i*a[0];
         }
         for(int ind = 1;ind<n;ind++){
             for(int N = 0;N<=n;N++){
                 //recusive relation
                    int notpick = 0 + prev[N];
                    int pick = INT_MIN;
                    if(N >= (ind+1)){
                        pick = a[ind] + curr[N-(ind+1)];
                    }
                    curr[N] = max(pick,notpick);
             }
             prev = curr;
         }
        return prev[n];
    }
    int so1(int n,vector<int>&a){
        vector<int> prev(n+1,0);
        //base case
         for(int i = 0;i<=n;i++){
             prev[i] = i*a[0];
         }
         for(int ind = 1;ind<n;ind++){
             for(int N = 0;N<=n;N++){
                 //recusive relation
                    int notpick = 0 + prev[N];
                    int pick = INT_MIN;
                    if(N >= (ind+1)){
                        pick = a[ind] + prev[N-(ind+1)];
                    }
                    prev[N] = max(pick,notpick);
             }
         }
        return prev[n];
    }
    int cutRod(vector<int> &price) {
        int ans = -1;
        int n = price.size();
        
        //RECURSION (TC-> exponential,SC->O(target))
        // ans = rec(n-1,n,price);
        
        //MEMOIZATION (TC-> O(n*n),SC->O(n*n + n))
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // ans = mem(n-1,n,price,dp);
        
        //TABULATION(TC-> O(n*n),SC->O(n*n))
        // ans = tab(n,price);
        
        //SPACE OPTIMIZATION(TC-> O(n*n),SC->O(n+n))
        // ans = so(n,price);
        
        //1D optimization(TC-> O(n*n),SC->O(n))
        ans = so1(n,price);
 
        return ans;
    }
};