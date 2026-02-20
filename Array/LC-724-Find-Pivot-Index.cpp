class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i]) {
                return i;
            }
        }
        return -1;
    }
};
// Equation based optimized code
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            Sum += nums[i];
        }
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) { 
            // Sum = leftSum + nums[i] + rightSum
            // rightSum = Sum-leftSum-nums[i]
            //leftSum = rightSum
            if (leftSum == Sum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};