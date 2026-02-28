//Donut Method
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = nums[0];
        int currMax = nums[0]; 
        int maxSum = nums[0]; 
        int currMin = nums[0];
        int maxMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            totalSum =totalSum + nums[i];
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);
            currMin = min(nums[i], currMin + nums[i]);
            maxMin = min(maxMin, currMin);
        }
    //When all elements are negative then totalSum-maxMin is 0;
        if (maxSum < 0)
            return maxSum;
        return max(maxSum, totalSum - maxMin);
    }
};
