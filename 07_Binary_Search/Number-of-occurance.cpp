class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int first = -1;
        int last = -1;
        if (arr.size() == 0)
            return 0;
        int low = 0;
        int high = arr.size() - 1;
        // first occurance
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;
                continue;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // if first occurance is not availble then number of occurance is zero
        if (first == -1)
            return 0;
        // last occurance
        low = first
        high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                index[1] = mid;
                low = mid + 1;
                continue;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        //difference of first & last occurance +1 is total occurance
        return (index[1]-index[0]+1);
    }
};
