class Solution {
public:
bool isPalindrome(int i,int j,string&s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int rec(int i,string&s){
    int n = s.length();
    if(i==n) return 0;
    int min_cuts = INT_MAX;
    for(int j = i;j<n;j++){
        if(isPalindrome(i,j,s)){
            int  cuts = 1 + rec(j+1,s);
            min_cuts = min(min_cuts,cuts);
        }
    }
        return min_cuts;
}
int mem(int i,string&s,vector<int>&dp){
    int n = s.length();
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int min_cuts = INT_MAX;
    for(int j = i;j<n;j++){
        if(isPalindrome(i,j,s)){
            int  cuts = 1 + mem(j+1,s,dp);
            min_cuts = min(min_cuts,cuts);
        }
    }
        return dp[i] = min_cuts;
}
int tab(string&s){
    int n = s.length();
    vector<int>dp(n+1,0);
    for(int i = n-1;i>=0;i--){
        int min_cuts = INT_MAX;
        for(int j = i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int  cuts = 1 + dp[j+1];
                min_cuts = min(min_cuts,cuts);
            }
        }
        dp[i] = min_cuts;        
    }
    return dp[0];
}
    int minCut(string s) {
        int n = s.length();
        int ans = 0;

        //RECURSION
        // ans= rec(0,s);

        //MEMOIZATION
        // vector<int>dp(n,-1);
        // ans = mem(0,s,dp);

        //TABULATION
        ans = tab(s);

        return ans-1;
    }
};