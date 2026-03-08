class Solution {
public:
    int findMin(vector<int>& nums) {
       int n = nums.size();
       int start = 0;
       int end = n-1;
       if(nums[start] < nums[end]){
        //array is not rotated
        return nums[start];
       } 
       //guess answer should be monotonic like no no no yes yes yes
       while(start<end){
        int guess = start + (end-start)/2;
        if(nums[guess] <= nums[n-1]){
            //we are in 1234 part of 5671234 and guess may be my answer
            end = guess;
        }else{
            //we are in 567 part of 5671234
            start = guess+1;
        }
       }
       return nums[start];//start and end both points at smallest element
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
       int n = nums.size();
       int start = 0;
       int end = n-1;
       int res = INT_MAX;
       if(nums[start] < nums[end]){
        //array is not rotated
        return nums[start];
       } 
       //guess answer should be monotonic like no no no yes yes yes
       while(start<=end){
        int guess = start + (end-start)/2;
        if(nums[guess] <= nums[n-1]){
            //we are in 1234 part of 5671234 and guess may be my answer
            res = min(res,nums[guess]);
            end = guess-1;
        }else{
            //we are in 567 part of 5671234
            start = guess+1;
        }
       }
       return res;
    }
};