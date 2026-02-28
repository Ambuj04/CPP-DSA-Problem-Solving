class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs[0].size();
        int size = strs.size();

        char ch;
        for (int i = 0; i < n; i++) {
            ch = strs[0][i];
            for (int j = 1; j < size; j++) {
                if (strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};