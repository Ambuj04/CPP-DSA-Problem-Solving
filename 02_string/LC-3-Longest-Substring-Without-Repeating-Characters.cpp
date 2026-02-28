class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int k;
        int low = 0;
        int high = 0;
        int result = 0;
        unordered_map<char, int> hashmap;
        while (high < n) {
            hashmap[s[high]]++;
            k = high - low + 1;
            while (hashmap.size() < k) {
                hashmap[s[low]]--;
                if (hashmap[s[low]] == 0) {
                    hashmap.erase(s[low]);
                }
                low++;
                k = high - low + 1;
            }
            result = max(result, k);
            high++;
        }
        return result;
    }
};