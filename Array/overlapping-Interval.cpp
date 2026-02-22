class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        // Code Here
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int end1;
        int start2;
        for(int i = 0;i<n-1;i++){
            end1  = intervals[i][1];
            start2 = intervals[i+1][0];
            if(start2 <= end1){
                return true;
            }
        }
      return false;
    }
};