class Solution {
public:
    bool so(int n, int target, vector<int>& a) {
        //(tc O(n*target),sc O(target)
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        prev[0] = true;
        if (a[0] <= target)
            prev[a[0]] = true;
        for (int ind = 1; ind < n; ind++) {
            curr[0] = true; // IMPORTANT
            for (int i = 1; i <= target; i++) {
                bool inclusive = false;
                if (a[ind] <= i)
                    inclusive = prev[i - a[ind]];
                bool exclusive = prev[i];
                curr[i] = inclusive || exclusive;
            }
            prev = curr;
        }
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
         int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2)
            return false; // odd sum can't split into two equal subset
        //subse sum equal to k
        int n = nums.size();
        int target = sum/2;
        return so(n,target,nums);
    }
};