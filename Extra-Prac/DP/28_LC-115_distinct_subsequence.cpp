class Solution {
public:
    int rec(int i,int j,string s1, string s2){
        //base case
        if(j<0) return 1;//2nd string is exhausted means match is found
        if(i<0) return 0;//1st string exhausted and 2nd string still remaining means not found
        if(s1[i]==s2[j]){
            return rec(i-1,j-1,s1,s2) + rec(i-1,j,s1,s2);
            //we go for take match or go deeper
        }else{
            return rec(i-1,j,s1,s2);
            //match not found so move index of s1
        }
    }
    int mem(int i,int j,string &s1, string &s2,vector<vector<int>> &dp){
        //base case
        if(j<0) return 1;//2nd string is exhausted means match is found
        if(i<0) return 0;//1st string exhausted and 2nd string still remaining means not found
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
          return  dp[i][j] = mem(i-1,j-1,s1,s2,dp) + mem(i-1,j,s1,s2,dp);
            //we go for take match or go deeper
        }else{
           return dp[i][j] = mem(i-1,j,s1,s2,dp);
            //match not found so move index of s1
        }
    }
    int mem1(int i,int j,string &s1, string &s2,vector<vector<int>> &dp){
        //base case
        if(j==0) return 1;//2nd string is exhausted means match is found
        if(i==0) return 0;//1st string exhausted and 2nd string still remaining means not found
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]){
          return  dp[i][j] = mem1(i-1,j-1,s1,s2,dp) + mem1(i-1,j,s1,s2,dp);
            //we go for take match or go deeper
        }else{
           return dp[i][j] = mem1(i-1,j,s1,s2,dp);
            //match not found so move index of s1
        }
    }
    int tab(int n,int m,string &s1, string &s2){
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        //base case
        for(int i = 0 ;i <= n;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] =  dp[i-1][j];
                }
            }
        }
            return (int)dp[n][m];
    }
    int so1(int n,int m,string &s1, string &s2){
        vector<double> prev(m+1,0),curr(m+1,0);
        //base case
        prev[0] = curr[0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }else{
                    curr[j] =  prev[j];
                }
            }
            prev = curr;
        }
            return (int)prev[m];
    }

    int so2(int n,int m,string &s1, string &s2){
        vector<double> prev(m+1,0);
        //base case
        prev[0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = m;j >= 1;j--){
                if(s1[i-1]==s2[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }
            }
        }
            return (int)prev[m];
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        int ans = 0;

        //RECURSION
        // ans = rec(n-1,m-1,s,t);

        //MEMOIZATION
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // ans = mem(n-1,m-1,s,t,dp);
        
        //MEMOIZATION 1 BASED INDEXING
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // ans = mem1(n,m,s,t,dp); 

        //TABULATION
        // ans = tab(n,m,s,t);   

        //SPACE OPTIMIZATON
        // ans = so1(n,m,s,t);    

        //SPACE OPTIMIZATION 1D
        ans = so2(n,m,s,t);

        return ans;
    }
};