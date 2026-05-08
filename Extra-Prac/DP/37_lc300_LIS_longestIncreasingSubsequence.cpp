class Solution {
public:
    int rec(int ind,int prev_ind,int&n,vector<int>&a){
        //TC-> O(2^n)  SC->O(n)
        if(ind==n) return 0;
        int nottake = rec(ind+1,prev_ind,n,a);
        int take = INT_MIN;
        if(prev_ind == -1 || a[ind] > a[prev_ind]){
            take = 1 + rec(ind+1,ind,n,a);
        }
        return max(take,nottake);
    } 
    int mem(int ind,int prev_ind,int&n,vector<int>&a,vector<vector<int>>&dp){
        //TC-> O(n^2)  SC->O(n^2 + n)
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int nottake = mem(ind+1,prev_ind,n,a,dp);
        int take = 0;
        if(prev_ind == -1 || a[ind] > a[prev_ind]){
            take = 1 + mem(ind+1,ind,n,a,dp);
        }
        return dp[ind][prev_ind+1] = max(take,nottake);
    }
    int tab(vector<int>& a) {
        //TC-> O(n^2)  SC->O(n^2)
        int n = a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind = n-1 ;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
                int nottake = dp[ind+1][prev_ind+1];
                int take = 0;
                if(prev_ind == -1 || a[ind] > a[prev_ind]){
                    take = 1 + dp[ind+1][ind+1];;
                }
                dp[ind][prev_ind+1] = max(take,nottake);                
            }
        }
        return dp[0][0];
    }
    int so(vector<int>& a) {
        //TC-> O(n^2)  SC->O(2n)
        int n = a.size();
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int ind = n-1 ;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
                int nottake = prev[prev_ind+1];
                int take = 0;
                if(prev_ind == -1 || a[ind] > a[prev_ind]){
                    take = 1 + prev[ind+1];;
                }
                curr[prev_ind+1] = max(take,nottake);                
            }
            prev = curr;
        }
        return prev[0];
    }
    int algo(vector<int>& arr) {
        //TC-> O(n^2)  SC->O(n)
        int maxi = 0;
        int n = arr.size();
        vector<int>dp(n,1);
        for(int i = 0;i<n;i++){
            for(int prev_ind = 0;prev_ind<i;prev_ind++){
                if(arr[prev_ind]<arr[i]){
                    dp[i] = max(dp[i],1+dp[prev_ind]);
                }
                maxi= max(maxi,dp[i]);
            }
        }
        return maxi;
    }
    int bs(vector<int>& arr) {
        //TC-> O(nlogn)  SC->O(n)
        int n = arr.size();
        vector<int>temp;
        int len = 1;
        temp.push_back(arr[0]);
        for(int i = 1;i<n;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
                len++;
            }else{
            auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
            // iterator pointing to first element >= arr[i]

            int prev_ind = it - temp.begin();
            // distance from beginning = index
            temp[prev_ind] = arr[i];
            }
        }
        return len;
    }
    vector<int> print(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0; i < n; i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[i] > arr[prev] && dp[prev] + 1 > dp[i]) {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            } 
        if(dp[i] > maxi) {
            maxi = dp[i];
         lastIndex = i;
        }
    }
    }
    vector<int> lis;
    lis.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
       lis.push_back(arr[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans  = 0;

        //RECURSION
        // ans = rec(0,-1,n,nums);

        //MEMOIZATION(1 based indexing for deal with -1)
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // ans = mem(0,-1,n,nums,dp);

        //TABULATION
        // ans = tab(nums);

        //SPACE OPTIMIZATION
        // ans = so(nums);

        //ALGORITHM
        // ans = algo(nums);
        
        //PRINT
        vector<int> lis = print(nums);
        ans = lis.size();

        //LIS using BS
        // ans = bs(nums);



        return ans;
    }
};