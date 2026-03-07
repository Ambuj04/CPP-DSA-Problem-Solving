// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int res = INT_MAX;
        if (arr.size() == 0)
            return -1;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                res = min(res,mid);
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};