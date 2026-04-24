class Solution {
  public:
  int rec(int i,int j,vector<vector<int>>& a){
      int n = a.size();
      if(i == n-1) return a[n-1][j];
      //no boundary condition required
      int down = a[i][j] + rec(i+1,j,a);
      int diagonal = a[i][j] + rec(i+1,j+1,a);
      return min(down,diagonal);
  }
int mem(int i,int j,vector<vector<int>>& a,vector<vector<int>>&dp){
      int n = a.size();
      if(i == n-1) return a[n-1][j];
      //no boundary condition required
      if(dp[i][j]!=-1) return dp[i][j];
      int down = a[i][j] + mem(i+1,j,a,dp);
      int diagonal = a[i][j] + mem(i+1,j+1,a,dp);
      return dp[i][j] = min(down,diagonal);
  }
int tab(vector<vector<int>>& a){
      int n = a.size();
      vector<vector<int>>dp(n,vector<int>(n,-1));
        //base case
        for(int j = 0 ;j<n;j++){
            dp[n-1][j] = a[n-1][j];
        }
        for(int i = n-2;i>=0;i--){
            for(int j = i;j>=0;j--){
                int down = a[i][j] + dp[i+1][j];
                int diagonal = a[i][j] + dp[i+1][j+1];
                dp[i][j]= min(down,diagonal);
            }
        }
      return dp[0][0];
  }
  int so(vector<vector<int>>& a){
      int n = a.size();
        vector<int> front(n),curr(n);
        //base case
        for(int j = 0 ;j<n;j++){
           front[j] = a[n-1][j];
        }
        for(int i = n-2;i>=0;i--){
            for(int j = i;j>=0;j--){
                int down = a[i][j] + front[j];
                int diagonal = a[i][j] + front[j+1];
                curr[j]= min(down,diagonal);
            }
            front = curr;
        }
      return front[0];
  }
    int minPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
       int ans;
    //   ans = rec(0,0,triangle);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // ans = mem(0,0,triangle,dp);
        // ans = tab(triangle);
        ans = so(triangle);
        return ans;
    }
};