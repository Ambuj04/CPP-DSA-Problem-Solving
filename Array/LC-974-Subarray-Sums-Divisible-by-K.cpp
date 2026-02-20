class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap; // map prefix sum with seen in previous or not (map prefix sum with frequency)
        int sum = 0;
        int n = nums.size();
        hashmap[0] = 1; // prefix sum of empty subarray is 0 which is seen 1
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            // if two prefixes leave the same remainder when divided by k, their difference is divisible by k.
            int rem = sum % k;
            if (rem < 0){
                //if any negative appear then remainder is negative but remainder lie between 0 to 5
                rem += k;
            }
            // remainder repeats means we find answer
            res += hashmap[rem];
            hashmap[rem]++;
        }
        return res;
    }
};