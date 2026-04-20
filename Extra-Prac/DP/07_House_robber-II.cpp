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
        vector<int> temp1, temp2;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != (n - 1))
                temp2.push_back(nums[i]);
        }
        int ans = max(so(temp1), so(temp2));
        return ans;
    }
};