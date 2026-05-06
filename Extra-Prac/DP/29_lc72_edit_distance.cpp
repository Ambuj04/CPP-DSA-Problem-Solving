class Solution {
public:
    int rec(int i,int j,string&s1,string&s2){
        //base case
        if(i<0) return j+1;
        if(j<0) return i+1;
        //match found
        if(s1[i]==s2[j]) return rec(i-1,j-1,s1,s2);
        //match not found
        return  1 + min(rec(i,j-1,s1,s2),min(rec(i-1,j,s1,s2),rec(i-1,j-1,s1,s2)));
    }
    int mem(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
        //base case
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        //match found
        if(s1[i]==s2[j]) return dp[i][j] = mem(i-1,j-1,s1,s2,dp);
        //match not found
        return dp[i][j] = 1 + min(mem(i,j-1,s1,s2,dp),min(mem(i-1,j,s1,s2,dp),mem(i-1,j-1,s1,s2,dp)));
    }
    int mem1(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
        //base case
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        //match found
        if(s1[i-1]==s2[j-1]) return dp[i][j] = mem1(i-1,j-1,s1,s2,dp);
        //match not found
        return dp[i][j] = 1 + min(mem1(i,j-1,s1,s2,dp),min(mem1(i-1,j,s1,s2,dp),mem1(i-1,j-1,s1,s2,dp)));
    }
    int tab(int n,int m,string&s1,string&s2){
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        //base case
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int i = 1 ;i<=n;i++){
            for(int j = 1;j<=m;j++){
                //match found
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                //match not found
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return (int)dp[n][m];
    }
    int so(int n,int m,string&s1,string&s2){
        vector<double> prev(m+1,0),curr(m+1,0);
        //base case
        for (int j = 0; j <= m; j++) prev[j] = j;
        for(int i = 1 ;i<=n;i++){
            curr[0] = i;
            for(int j = 1;j<=m;j++){
                //match found
                if(s1[i-1]==s2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                //match not found
                curr[j] = 1 + min(curr[j-1],min(prev[j],prev[j-1]));
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int ans;

        //RECURSION
        // ans = rec(n-1,m-1,word1,word2);

        //MEMOIZATOIN
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // ans = mem(n-1,m-1,s1,s2,dp);

        //MEMOIZATOIN 1 BASED
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // ans = mem1(n,m,s1,s2,dp);
        // return ans;

        //TABULAITON
        // ans = tab(n,m,s1,s2);

        //SPACE OPTIMIZATION
        ans = so(n,m,s1,s2);
        return ans;
    }
};