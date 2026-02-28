// A better optimized code is written below
class Solution
{
public:
    bool included(vector<int> &need, vector<int> &have)
    {
        for (int i = 0; i < 256; i++)
        {
            if (need[i] != 0 && need[i] > have[i])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int n = t.length();
        int m = s.length();
        if (m < n)
        {
            return "";
        }
        int high = 0;
        int low = 0;
        int start;
        int len;
        int res = INT_MAX;
        vector<int> need(256, 0);
        vector<int> have(256, 0);
        for (int i = 0; i < n; i++)
        {
            need[t[i]]++;
        }
        while (high < m)
        {
            have[s[high]]++;
            while (included(need, have))
            {
                len = high - low + 1;
                if (res > len)
                {
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
            high++;
        }
        if (res == INT_MAX)
            return "";
        return s.substr(start, res);
    }
};
/////////////////////////////////////////
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        vector<int> need(256, 0);
        // Step 1: build frequency map
        for (char c : t)
        {
            need[(unsigned char)c]++; // usigned char used for if compiler have negaitve value for char then it prevent it
        }
        int required = t.size();
        int low = 0;
        int minLen = INT_MAX;
        int start = 0;
        // Step 2: expand window
        for (int high = 0; high < s.size(); high++)
        {
            char ch = s[high];
            // If this character was needed
            if (need[(unsigned char)ch] > 0)
            {
                required--;
            }
            need[(unsigned char)ch]--;
            // Step 3: shrink when valid
            while (required == 0)
            {
                if (high - low + 1 < minLen)
                {
                    minLen = high - low + 1;
                    start = low;
                }
                char leftChar = s[low];
                need[(unsigned char)leftChar]++;
                if (need[(unsigned char)leftChar] > 0)
                {
                    required++;
                }
                low++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
