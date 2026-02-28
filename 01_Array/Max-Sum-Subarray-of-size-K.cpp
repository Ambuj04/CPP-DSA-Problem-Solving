class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
        {
            return arr[0];
        }
        int maxi = INT_MIN;
        int sum = 0;
        int left = 0;
        int right = k - 1;
        for (int i = left; i <= right; i++)
        {
            sum = sum + arr[i];
        }
        while (right < n)
        {
            maxi = max(sum, maxi);
            left++;
            right++;
            //This needs special attention
            if (right == n)
            {
                break;
            }
            sum = sum - arr[left - 1] + arr[right];
        }
        return maxi;
    }
};