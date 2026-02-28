class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = nums[0];
        int maxproduct = nums[0];
        int minproduct = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(minproduct, maxproduct);
            minproduct = min(nums[i], minproduct * nums[i]);
            maxproduct = max(nums[i], maxproduct * nums[i]);
            res = max(res, maxproduct);
        }
        return res;
    }
};
