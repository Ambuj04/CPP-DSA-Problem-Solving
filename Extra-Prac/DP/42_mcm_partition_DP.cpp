class Solution {
  public:
    int rec(int i,int j,vector<int>&arr){
        if(i==j) return 0;
        int mini = 1e9;
        for(int k = i;k < j ;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + rec(i,k,arr) + rec(k+1,j,arr);
            mini = min(steps,mini);
        }
        return mini;
    }
    int mem(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k = i;k < j ;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + mem(i,k,arr,dp) + mem(k+1,j,arr,dp);
            mini = min(steps,mini);
        }
        return mini;
    }
  int tab(vector<int> &arr) {
        int n= arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0)); 
        for(int i = n-1 ;i >= 1;i--){
            for(int j = i+1;j<=n-1;j++){
                int mini = 1e9;
                for(int k = i;k < j ;k++){
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k]+ dp[k+1][j];
                    mini = min(steps,mini);
                }
                dp[i][j] = mini;                
            }
        }
        return dp[1][n-1];
  }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        
        //RECURSION
        // ans = rec(1,n-1,arr);
        
        //MEMOIZATION
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // ans = mem(1,n-1,arr,dp);
        
        //TABULAITON
        ans = tab(arr);
        
        return ans;
    }
};