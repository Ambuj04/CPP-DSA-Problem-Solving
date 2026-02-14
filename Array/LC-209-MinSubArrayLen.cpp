class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int sum = nums[0];
        int res = INT_MAX;
        while (right < n)
        {
            if (sum >= target)
            {
                res = min(res, (right - left + 1));
                sum = sum - nums[left];
                left++;
            }
            else
            {
                right++;
                if (right == n)
                {
                    break;
                }
                sum = sum + nums[right];
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};