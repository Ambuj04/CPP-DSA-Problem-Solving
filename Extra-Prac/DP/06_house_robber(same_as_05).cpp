//LC-198
class Solution
{
public:
    int so(vector<int> &arr)
    {
        int n = arr.size();
        int prev2 = 0;
        int prev = arr[0];
        int curr;
        for (int i = 1; i < n; i++)
        {
            int include = arr[i] + prev2;
            int exclude = prev;
            curr = max(include, exclude);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return so(nums);
    }
};