class Solution {
  public:
    bool func(vector<int>&stalls,int guess,int k){
        //we calculate number of adjacent cows possible with givend guess distance
        int n = stalls.size();
        int pos=stalls[0];
        int cow = 1;
        for(int i = 1;i<n;i++){
            int dist = stalls[i] - pos;
            if(dist < guess){
                continue;
            }
            cow++;
            pos = stalls[i];
        }
        if(cow >= k) return true;
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int start = 0;
        int end = stalls[n-1] - stalls[0];
        while(start<=end){
            int guess  =  start + (end-start)/2;
            if(func(stalls,guess,k)){
                start = guess+1;
            }else{
                end = guess-1;
            }
        }
        
        return end ;
    }
};
