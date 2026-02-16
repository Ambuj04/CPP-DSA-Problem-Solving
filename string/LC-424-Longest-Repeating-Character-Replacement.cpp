class Solution {
public:
    int maxFreq(vector<int>& ft) {
        int maxi = INT_MIN;
        for (int i = 0; i < 26; i++) {
            maxi = max(ft[i], maxi);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        vector<int> ft(26, 0);
        int low = 0;
        int result = -1;
        int len;
        int maxfreq;
        int diff;
        int high = 0;
        int n = s.length();
        while (high < n) {
            //high included in answer
            ft[s[high] - 'A']++;
            len = high - low + 1;
            maxfreq = maxFreq(ft);
            diff = len - maxfreq;
            // low++ untill wrong is included
            while (diff > k) {
                ft[s[low] - 'A']--;
                low++;
                maxfreq = maxFreq(ft);
                len = high - low + 1;
                diff = len - maxfreq;
            }
            //store the right answer
            result = max(result, len);
            high++;
        }
        return result;
    }
};