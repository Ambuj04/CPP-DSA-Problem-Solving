/*
number of 0 = 5
number of 1 = 6
difference of zeroes and ones = -1 means in future we see -1 difference means
lenght between same difference is correct answer. number of 0 = 30 number of 1 =
31 difference = -1 (same than previous) means between same difference there are
25 0's and 25 1's is occured.
*/
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        int diff;
        int res = 0;
        int zeroes = 0;
        int ones = 0;
        unordered_map<int, int> hashmap; // difference -> at index
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zeroes++;
            }
            else
            {
                ones++;
            }
            diff = zeroes - ones;
            if (diff == 0)
            {
                res = max(res, i + 1); // i+1 is length
            }
            else
            {
                // for find index (hashmap[diff] > 0) this line is problematic because it creates the unwanted hashmap means diff at index 0
                if (hashmap.find(diff) != hashmap.end())
                {
                    res = max(res, i - hashmap[diff]);
                }
                else
                {
                    hashmap[diff] = i;
                }
            }
        }
        return res;
    }
};