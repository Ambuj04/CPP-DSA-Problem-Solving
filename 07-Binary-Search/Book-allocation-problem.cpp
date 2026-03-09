class Solution {
  public:
    //helper function
    bool func(vector<int>&books,int limit,int students){
        int k = 1; //focus on 1st student
        int page = 0;
        for(int i = 0 ; i<books.size();i++){
            if(page + books[i] <= limit){
                page = page+books[i];
            }else{
                k++;
                page = books[i];
                if(k>students){
                    return false;
                }
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        int start=0;
        int end = 0;
        for(auto num:arr){
            start = max(start,num);
            end += num;
        }
        while(start<=end){
            int guess = start + (end-start)/2;
            if(func(arr,guess,k)){
                end = guess-1;
            }else{
                start = guess+1;
            }
        }
        return start;
    }
};