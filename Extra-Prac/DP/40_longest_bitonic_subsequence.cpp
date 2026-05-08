class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int>dp1(n,1);
        for(int i = 0;i<n;i++){
            for(int prev_ind = 0;prev_ind<i;prev_ind++){
                if(nums[prev_ind]<nums[i]){
                    dp1[i] = max(dp1[i],1+dp1[prev_ind]);
                }
            }
        }
        vector<int>dp2(n,1);
        for(int i = n-1;i>=0;i--){
            for(int prev_ind = n-1;prev_ind>i;prev_ind--){
                if(nums[prev_ind]<nums[i]){
                    dp2[i] = max(dp2[i],1+dp2[prev_ind]);
                }
            }
        }
        int maxi = 0;
        for(int i = 0;i<n;i++){
             // both sides must exist
            if(dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
  
        return maxi;
    }
};
