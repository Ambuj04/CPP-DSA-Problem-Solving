//space complexity O(n)
//Time complexity O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
       int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if (end1 < start2) {
                // merge not occur
                ans.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            } else {
                // merge occur
                end1 = max(end1, end2);
            }
        }
        ans.push_back({start1, end1}); // push last valid interval in answer
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> newVector;
        if (n == 0) {
            newVector.push_back(newInterval);
            return newVector;
        }
        bool insert = false;
        int start1;
        for (int i = 0; i < n; i++) {
            start1 = intervals[i][0];
            if (insert == false && start1 >= newInterval[0]) {
                newVector.push_back(newInterval);
                insert = true;
            }
            newVector.push_back(intervals[i]);
        }
        // if interval is over and newInterval still not insert then put it last 
        if (insert == false) {
            newVector.push_back(newInterval);
        }
        // merge interals
        return merge(newVector);
    }
};
///////////////////////////////optimal code///////////////////////////////////
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        // Case 1: no overlapping case before the merge intervals
        // Compare ending point of intervals to starting point of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        // Case 2: overlapping case and merging of intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // Case 3: no overlapping of intervals after newinterval being merged
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};