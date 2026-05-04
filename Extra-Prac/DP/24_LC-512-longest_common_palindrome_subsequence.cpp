class Solution {
public:
    int LCS(int n1,int n2,string& s1,string&s2){
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));   //1 Based indexing because -1 represent as 0 for base case
        //base case (-1 means answer is 0)
        for(int i = 0;i<=n1;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i<=n2;i++){
            dp[0][i] = 0;
        }
        //recursive relation
        for(int ind1 = 1;ind1<=n1;ind1++){
            for(int ind2 = 1;ind2<=n2;ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    int match = 1 + dp[ind1-1][ind2-1];//match found
                     dp[ind1][ind2] = match;
                }else{
                    int notmatch = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                    dp[ind1][ind2] = notmatch;
                }
            }
        }
        return dp[n1][n2];
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        int n = s.length();
        //lcs
        return LCS(n,n,s1,s2);
        
    }
};