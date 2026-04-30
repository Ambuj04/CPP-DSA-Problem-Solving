class Solution
{
public:
    int so(int n, int target, vector<int> &a)
    {
        vector<int> prev(target + 1), curr(target + 1);
        // base case
        if (a[0] == 0)
        {
            prev[0] = 2;
        }
        else
        {
            prev[0] = 1;
        }
        if (a[0] != 0 && a[0] <= target)
        {
            prev[a[0]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int inclusive = 0;
                if (a[i] <= tar)
                {
                    inclusive = prev[tar - a[i]];
                }
                int exclusive = prev[tar];
                curr[tar] = (inclusive + exclusive);
            }
            prev = curr;
        }
        return prev[target];
    }
    int countPartitions(vector<int> &arr, int diff)
    {
        int total = 0;
        for (int i : arr)
            total += i;
        if ((total - diff) < 0 || (total - diff) % 2 == 1)
        {
            return 0;
        }
        int target = (total - diff) / 2;
        int n = arr.size();
        return so(n, target, arr);
    }
};