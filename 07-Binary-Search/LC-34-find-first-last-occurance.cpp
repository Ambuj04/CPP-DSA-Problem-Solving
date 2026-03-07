class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0)
            return res;
        int low = 0;
        int high = nums.size() - 1;
        // first occurance
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                res[0] = mid;
                high = mid - 1;
                continue;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // if first occurance is not availble then no need to search last occurance
        if (res[0] == -1)
            return res;
        // last occurance
        low = res[0];
        high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                res[1] = mid;
                low = mid + 1;
                continue;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};