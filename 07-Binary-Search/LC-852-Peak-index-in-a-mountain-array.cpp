class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(arr[mid] < arr[mid+1]){
                //you are left side of peak
                start = mid+1;
            }else if(arr[mid] > arr[mid+1]){
                //you are right side of peak and may be index included in mid
                end = mid;
            }
        }
        return start;//start and end is at same index which is peak index
    }
};