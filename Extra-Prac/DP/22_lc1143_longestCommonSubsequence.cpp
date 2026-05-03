class Solution {
public:
    int rec(int ind1,int ind2,string& s1,string&s2){
        //base case
        if(ind1<0 || ind2<0){
            return 0;
        }
        //recursive relation
        if(s1[ind1] == s2[ind2]){
            int match = 1 + rec(ind1-1,ind2-1,s1,s2);//match found
            return match;
        }else{
            int notmatch = max(rec(ind1-1,ind2,s1,s2),rec(ind1,ind2-1,s1,s2));//search both possibility of move 1 forward
            return notmatch;
        }

    }
    int mem1(int ind1,int ind2,string& s1,string&s2,vector<vector<int>>&dp){
        //base case
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        //recursive relation
        if(s1[ind1] == s2[ind2]){
            int match = 1 + mem1(ind1-1,ind2-1,s1,s2,dp);//match found
            return dp[ind1][ind2] = match;
        }else{
            int notmatch = max(mem1(ind1-1,ind2,s1,s2,dp),mem1(ind1,ind2-1,s1,s2,dp));//search both possibility of move 1 forward
            return dp[ind1][ind2] = notmatch;
        }
    }
    int mem2(int ind1,int ind2,string& s1,string&s2,vector<vector<int>>&dp){
        //base case
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        //recursive relation
        if(s1[ind1-1] == s2[ind2-1]){
            int match = 1 + mem2(ind1-1,ind2-1,s1,s2,dp);//match found
            return dp[ind1][ind2] = match;
        }else{
            int notmatch = max(mem2(ind1-1,ind2,s1,s2,dp),mem2(ind1,ind2-1,s1,s2,dp));//search both possibility of move 1 forward
            return dp[ind1][ind2] = notmatch;
        }
    }
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
        int len = dp[n1][n2];

        //for printing LCS
        string str = "";
        int i = n1,j = n2;
        while(i >= 1 && j>=1){
            //for match case
            if(s1[i-1] == s2[j-1]){
                str += s1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j] >  dp[i][j]){
                j--;
            }else{
                i--;
            }
        }
        reverse(str.begin(),str.end());
        cout<<str;
        return dp[n1][n2];
    }
    int so(int n1,int n2,string& s1,string&s2){
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
    int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        int n1 = text1.size();
        int n2 = text2.size();
        
        //RECURSION
        // ans = rec(n1-1,n2-1,text1,text2);

        //MEMOIZATION (0 based indexing)
        // vector<vector<int>>dp(n1,vector<int>(n2,-1));
        // ans = mem1(n1-1,n2-1,text1,text2,dp);

        //MEMOIZATION (1 based indexing)
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        // ans = mem2(n1,n2,text1,text2,dp);

        //TABULATION
        ans = tab(n1,n2,text1,text2);

        //SPACE OPTIMIZATION
        // ans = so(n1,n2,text1,text2);

        return ans;
    }
};