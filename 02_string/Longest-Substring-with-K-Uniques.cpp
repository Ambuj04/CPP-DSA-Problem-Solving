class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.length();
        int len;
        int low = 0;
        int high = 0;
        int result = -1;
        unordered_map<int, int> hashmap;
        while (high < n)
        {
            // high included in answer
            hashmap[s[high]]++;
            //decrease the low untill info is right 
            while (hashmap.size() > k)
            {
                hashmap[s[low]]--;
                if (hashmap[s[low]] == 0)
                {
                    hashmap.erase(s[low]);
                }
                low++;
            }
            // include right info in answer
            if (hashmap.size() == k)
            {
                len = high - low + 1;
                result = max(result, len);
            }
            high++;
        }
        return result;
    }
};