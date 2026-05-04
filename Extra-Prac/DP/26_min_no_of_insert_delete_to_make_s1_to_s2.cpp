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
    int minOperations(string &s1, string &s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int lcs = LCS(n1,n2,s1,s2);
        return (n1+n2-(2*lcs));
        
    }
};