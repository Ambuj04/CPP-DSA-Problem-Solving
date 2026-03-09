class Solution {
public:
int func(int n,int m,int guess){
        //give no of elem less than and equal to guess
        int row = n;
        int col = 1;
        int count = 0;
        while(row>=1 && col <= m){
            if((row*col)<=guess){
                    count = count+row;
                    col++;
            }else{
                row--;
            }
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
         int start  = 1;
        int end = n * m;
        while(start <= end){
            int guess = start + (end-start)/2;
            int ans = func(n,m,guess);
            if(ans < k){
                start = guess+1;
            }else{
                end = guess-1;
            }
        }
        return start ; //return first occurance of yes
    }
};