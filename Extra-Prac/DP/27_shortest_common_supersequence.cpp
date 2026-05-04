class Solution {
  public:
        int LCS(int n1,int n2,string& s1,string&s2){
        vector<int> prev(n2+1),curr(n2+1);
        //base case
        for(int i = 0;i<=n2;i++){
           prev[i] = 0;
        }
        //recursive relation
        for(int ind1 = 1;ind1<=n1;ind1++){
            for(int ind2 = 1;ind2<=n2;ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    int match = 1 + prev[ind2-1];//match found
                     curr[ind2] = match;
                }else{
                    int notmatch = max(prev[ind2],curr[ind2-1]);
                    curr[ind2] = notmatch;
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
    int minSuperSeq(string &s1, string &s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int lcs = LCS(n1,n2,s1,s2);
        return (n1+n2-lcs);
    }
};
////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
        string LCS(int n1,int n2,string& s1,string&s2){
        string str = "";
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));   
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
        int i = n1,j = n2;
        while(i > 0 && j > 0){
            //for match case
            if(s1[i-1] == s2[j-1]){
                str += s1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j] >  dp[i][j-1]){
                str += s1[i-1];
                i--;
            }else{
                str += s2[j-1];
                j--;
            }
        }
        while(i>0){
                str += s1[i-1];
                i--;
        }
        while(j>0){
                str += s2[j-1];
                j--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        return  LCS(n1,n2,s1,s2);;
    }
};