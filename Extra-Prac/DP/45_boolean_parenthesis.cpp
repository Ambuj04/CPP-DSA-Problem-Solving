// User function Template for C++
#define ll long long
class Solution {
  public:
    int rec(int i,int j,int isTrue,string &a){
        if(i>j) return 0;
        if(i==j){
            if(isTrue)
                return a[i] == 'T';
            else
                return a[i] == 'F';}
        ll ways = 0;
        for(int ind = i+1;ind<=j-1;ind = ind+2){
            ll LT = rec(i,ind-1,1,a);
            ll LF = rec(i,ind-1,0,a);
            ll RT = rec(ind+1,j,1,a);
            ll RF = rec(ind+1,j,0,a);
            if(a[ind]=='&'){
                if(isTrue){
                    ways += LT*RT;
                }else{
                    ways += (LT*RF) + (LF*RT) + (LF*RF);
                }
            }
            if(a[ind]=='|'){
                if(isTrue){
                    ways += (LT*RF) + (LF*RT) + (LT*RT);
                }else{
                    ways += (LF*RF);
                }
            }
            if(a[ind]=='^'){
                if(isTrue){
                ways += (LT*RF) + (LF*RT);
            }else{
                ways += (LT*RT) + (LF*RF);
            }
            }
        }
        return ways;
    }
    int mem(int i,int j,int isTrue,string &a,vector<vector<vector<ll>>>&dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue)
                return a[i] == 'T';
            else
                return a[i] == 'F';}
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        ll ways = 0;
        for(int ind = i+1;ind<=j-1;ind = ind+2){
            ll LT = mem(i,ind-1,1,a,dp);
            ll LF = mem(i,ind-1,0,a,dp);
            ll RT = mem(ind+1,j,1,a,dp);
            ll RF = mem(ind+1,j,0,a,dp);
            if(a[ind]=='&'){
                if(isTrue){
                    ways += LT*RT;
                }else{
                    ways += (LT*RF) + (LF*RT) + (LF*RF);
                }
            }
            if(a[ind]=='|'){
                if(isTrue){
                    ways += (LT*RF) + (LF*RT) + (LT*RT);
                }else{
                    ways += (LF*RF);
                }
            }
            if(a[ind]=='^'){
                if(isTrue){
                ways += (LT*RF) + (LF*RT);
                }else{
                ways += (LT*RT) + (LF*RF);
                }
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    int tab(string &a){
        int n = a.length();
       vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,0)));
       for(int i = n-1;i>=0;i--){
           for(int j = i ;j<=n-1;j++){
               for(int isTrue = 1 ; isTrue >=0 ;isTrue--){
                if(i==j){
                    if(isTrue)
                        dp[i][j][1] = (a[i] == 'T');
                    else
                        dp[i][j][0] = (a[i] == 'F');
                    continue;
                }
                    ll ways = 0;
                    for(int ind = i+1;ind<=j-1;ind = ind+2){
                        ll LT = dp[i][ind-1][1];
                        ll LF = dp[i][ind-1][0];
                        ll RT = dp[ind+1][j][1];
                        ll RF = dp[ind+1][j][0];
                        if(a[ind]=='&'){
                            if(isTrue){
                                ways += LT*RT;
                            }else{
                                ways += (LT*RF) + (LF*RT) + (LF*RF);
                            }
                        }
                        if(a[ind]=='|'){
                            if(isTrue){
                                ways += (LT*RF) + (LF*RT) + (LT*RT);
                            }else{
                                ways += (LF*RF);
                            }
                        }
                        if(a[ind]=='^'){
                            if(isTrue){
                            ways += (LT*RF) + (LF*RT);
                            }else{
                            ways += (LT*RT) + (LF*RF);
                            }
                        }
                    }
                    
                    dp[i][j][isTrue] = ways;                   
               }
           }
           
       }
       return dp[0][n-1][1];
    }
    int countWays(string &s) {
        int ans = 0;
        int n = s.length();
        
        //RECURSION
        // ans = rec(0,n-1,1,s);
        
        //MEMOIZATION
        // vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
        // ans = mem(0,n-1,1,s,dp);
        
        //TABULATION
        ans = tab(s);
        return ans;
    }
};