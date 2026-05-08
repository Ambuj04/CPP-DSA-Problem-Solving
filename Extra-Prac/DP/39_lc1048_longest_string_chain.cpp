
class Solution {
public:
   static bool cmp(string& s1, string& s2) { return s1.length() < s2.length(); }
    bool compare(string&s1,string&s2){
        if(s1.length() != s2.length()+1) return false;
        int first = 0;
        int second = 0;
        while(first<s1.length()){
            if(second<s2.length() && s1[first]==s2[second]){
                first++;
                second++;
            }else{
                first++;
            }
        }
        return second == s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int maxi = 1;
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (compare(words[i], words[prev]) && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
                if (dp[i] > maxi) {
                    maxi = dp[i];
                }
            }
        }
        return maxi;
    }
};