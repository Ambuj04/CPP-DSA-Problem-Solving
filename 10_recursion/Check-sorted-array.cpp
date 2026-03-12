class Solution {
  public:
    bool solve(vector<int>&arr, int i){
        if(i >= arr.size()-1) return true;
        if(arr[i] > arr[i+1]) return false;
        return  solve(arr,i+1);
     
    }
    bool isSorted(vector<int>& arr) {
       
        return solve(arr,0);
    }
};