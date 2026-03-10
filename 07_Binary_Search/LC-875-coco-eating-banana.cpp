class Solution {
public:
    long long giveTime(vector<int>&piles,int speed,int h){
        long long time = 0;
        for(int num:piles){
            time = time + (num/speed);
            if(num%speed != 0){
                time++;
            }
            if(time > h){
                break;
                //invalid case and don't need to compute further
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end()); //max element of vector
        while(start <= end ){
            int guess = start + (end-start)/2;
            if(giveTime(piles,guess,h) > h){
                //we need more speed
                start = guess+1;
            }else{
                //may be answer and need to make answer small
                end = guess-1;
            }
        }
        return start;
    }
};