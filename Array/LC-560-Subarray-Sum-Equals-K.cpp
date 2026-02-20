class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>hashmap; // map prefix sum with seen in previous or not (map prefix sum with frequency)
        int sum = 0;
        int n = nums.size();
        hashmap[0] = 1; // prefix sum of empty subarray is 0 which is seen 1
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            res += hashmap[sum - k];
            hashmap[sum]++;
        }
        return res;
    }
};