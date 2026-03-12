class Solution {
public:
    void solve(int index, int n, string& digits, string& temp, vector<string>& res, unordered_map<char, string>& f) {
        // base case
        if (index == n) {
            res.push_back(temp);
            return;
        }

        // one by one stages pr jao through index
        for (int i = 0; i < f[digits[index]].size(); i++) {

            temp.push_back(f[digits[index]][i]);
            solve(index + 1, n, digits, temp, res, f);
            temp.pop_back();
        }

        // everything is done
        return;
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        int idx = 0;
        int n = digits.length();
        vector<string> res;
        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";
        solve(idx, n, digits, temp, res, f);
        return res;
    }
};