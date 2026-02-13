class Solution
{
public:
    long long countTriplets(int n, long long sum, long long arr[])
    {
        sort(arr, arr + n);
        int left;
        int right;
        long long count = 0;
        int currSum;
        for (int i = 0; i < (n - 2); i++)
        {
            left = i + 1;
            right = n - 1;
            while (left < right)
            {
                currSum = arr[i] + arr[left] + arr[right];
                if (currSum < sum)
                {
                    count += (right - left);
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return count;
    }
};