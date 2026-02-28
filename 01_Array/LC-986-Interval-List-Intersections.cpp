class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size();
        int m = secondList.size();
        int i = 0, j = 0;
        int first, second;
        int start1, end1, start2, end2;
        while (i < n && j < m) {
            start1 = firstList[i][0];
            end1 = firstList[i][1];
            start2 = secondList[j][0];
            end2 = secondList[j][1];
            // Example -> first => [1,5] , second => [2,10]
            if (start1 <= start2) {
                // intersection may occur
                if (end1 >= start2) {
                    // intersection is occur
                    first = max(start1, start2);
                    second = min(end1, end2);
                    res.push_back({first, second});
                }
            } else {
                // Example -> fist => [2,10] , second => [1,5]
                if (end2 >= start1) {
                    // intersection is occur
                    first = max(start1, start2);
                    second = min(end1, end2);
                    res.push_back({first, second});
                }
            }
            if (end1 <= end2) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};