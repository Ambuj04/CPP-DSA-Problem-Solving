class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int k = 2;
        int maximum;
        int low = 0;
        int high = 0;
        int result = -1;
        unordered_map<int, int> hashmap;
        while (high < n)
        {
            hashmap[fruits[high]]++;
            while (hashmap.size() > k)
            {
                hashmap[fruits[low]]--;
                if (hashmap[fruits[low]] == 0)
                {
                    hashmap.erase(fruits[low]);
                }
                low++;
            }
            if (hashmap.size() <= k)
            {
                maximum = high - low + 1;
                result = max(result, maximum);
            }
            high++;
        }
        return result;
    }
};