//Tabulation of LCS is required
class Solution {
  public:    
    int tab(int n1,int n2,string& s1,string&s2){
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));   //1 Based indexing because -1 represent as 0 for base case
        //base case (-1 means answer is 0)
        for(int i = 0;i<=n1;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i<=n2;i++){
            dp[0][i] = 0;
        }
        //recursive relation
        int ans = 0;
        for(int ind1 = 1;ind1<=n1;ind1++){
            for(int ind2 = 1;ind2<=n2;ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    int match = 1 + dp[ind1-1][ind2-1];//match found
                     dp[ind1][ind2] = match;
                     ans = max(ans,match);
                }else{
                    dp[ind1][ind2] = 0;
                }
            }
        }
        return ans;
    }
    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int ans = 0;
        ans = tab(n1,n2,s1,s2);
        return ans;
        
    }
};