class Solution {
public:
    int rec(int ind,vector<int>&arr,int&k){
        int n = arr.size();
        if(ind==n) return 0;
        int maxAns = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int j = ind;j < min(n,ind+k) ;j++){
            len++;
            if(arr[j]>maxi) maxi = arr[j];
            int sum = (len*maxi) + rec(j+1,arr,k);
            maxAns = max(maxAns,sum);
        }
        return maxAns;
    }
    int mem(int ind,vector<int>&arr,int&k,vector<int>&dp){
        int n = arr.size();
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int maxAns = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int j = ind;j < min(n,ind+k) ;j++){
            len++;
            if(arr[j]>maxi) maxi = arr[j];
            int sum = (len*maxi) + mem(j+1,arr,k,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[ind] = maxAns;
    }
    int tab(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        for(int ind = n-1;ind>=0;ind--){
            int maxAns = INT_MIN;
            int maxi = INT_MIN;
            int len = 0;
            for(int j = ind;j < min(n,ind+k) ;j++){
                len++;
                if(arr[j]>maxi) maxi = arr[j];
                int sum = (len*maxi) + dp[j+1];
                maxAns = max(maxAns,sum);
            }
            dp[ind] = maxAns;           
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        
        //RECURSION
        // ans = rec(0,arr,k);

        //MEMOIZATION
        // vector<int>dp(n,-1);
        // ans = mem(0,arr,k,dp);

        //TABULATION
        ans = tab(arr,k);

        return ans;
    }
};