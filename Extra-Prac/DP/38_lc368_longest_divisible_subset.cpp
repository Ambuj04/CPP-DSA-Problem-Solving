class Solution {
public:
vector<int> print(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0; i < n; i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i]) {
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

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return print(nums);
        
    }
};