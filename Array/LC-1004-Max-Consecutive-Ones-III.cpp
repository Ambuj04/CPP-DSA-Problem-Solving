class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int high = 0;
        int low = 0;
        int n = nums.size();
        if(k == n){//if we can replace all elements with 1 
            return n; // then whole array contain 1 and also the size of array is answer
        }
        int anotherCount = 0;//count number of another element than 1 
        int len;//length of the correct window
        int res = 0;//store max size of the window
        while(high<n){
            //include high in answer
        if(nums[high] != 1){
            anotherCount++;
        }
        //do operation or move low untill the window info is right
        while(anotherCount > k){
            if(nums[low] != 1){
            anotherCount--;
        }
        low++;
        }
        //store the answer
        len = high-low+1;
        res = max(res,len);
        high++;
        }
        return res;
    }
};