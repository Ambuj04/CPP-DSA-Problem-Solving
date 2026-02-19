class Solution
{
public:
    int smallestSumSubarray(vector<int> &a)
    {
        int sum = a[0];
        int mini = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            sum = min(a[i], sum + a[i]);
            mini = min(mini, sum);
        }
        return mini;
    }
};
