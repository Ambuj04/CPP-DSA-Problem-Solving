class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev] ) {
                    dp[i] = 1 + dp[prev];
                    //inheritance
                    cnt[i] = cnt[prev];
                }else if(nums[prev] < nums[i] && dp[i] == 1 + dp[prev]){
                    //increase the cnt bcz found same len lcs
                    cnt[i] += cnt[prev];

                }
            }
                maxi = max(maxi, dp[i]);
        }
        int lcslen = 0;
        for(int i = 0 ;i<n;i++){
            if(dp[i] == maxi){
                lcslen += cnt[i];
            }
        }
        return lcslen;
    }
};