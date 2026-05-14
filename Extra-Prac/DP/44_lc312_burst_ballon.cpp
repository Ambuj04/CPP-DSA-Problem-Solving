class Solution {
public:
    int rec(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        int maxi = -1e9;
        for(int ind = i;ind<=j;ind++){
            int price  = (nums[i-1] * nums[ind] * nums[j+1]) + rec(i,ind-1,nums) + rec(ind+1,j,nums);
            maxi = max(price,maxi);
        }
        return maxi;
    }
    int mem(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = -1e9;
        for(int ind = i;ind<=j;ind++){
            int price  = (nums[i-1] * nums[ind] * nums[j+1]) + mem(i,ind-1,nums,dp) + mem(ind+1,j,nums,dp);
            maxi = max(price,maxi);
        }
        return dp[i][j] = maxi;
    }
    int tab(vector<int>&nums){
        int n =nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = n-2 ;i>=1;i--){
            for(int j = 1;j<=n-2;j++){
                if(i>j) continue;
                    int maxi = -1e9;
                    for(int ind = i;ind<=j;ind++){
                        int price  = (nums[i-1] * nums[ind] * nums[j+1]) +dp[i][ind-1] + dp[ind+1][j];
                        maxi = max(price,maxi);
                    }
                     dp[i][j] = maxi;               
            }
        }
       return dp[1][n-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        int ans = 0;


        //RECURSION
        // ans = rec(1,n-2,nums);

        //MEMOIZATION
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // ans = mem(1,n-2,nums,dp);

        //TABULATION
        ans = tab(nums);
        return ans;
    }
};