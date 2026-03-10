class Solution {
public:
    int func(vector<vector<int>>&matrix,int n,int m,int guess){
        //give no of elem less than and equal to guess
        int row = n-1;
        int col = 0;
        int count = 0;
        while(row>=0 && col < m){
            if(matrix[row][col]<=guess){
                    count = count+row+1;
                    col++;
            }else{
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int start  = matrix[0][0];
        int n = matrix.size(),m = matrix[0].size();
        int end = matrix[n-1][m-1];
        while(start <= end){
            int guess = start + (end-start)/2;
            int ans = func(matrix,n,m,guess);
            if(ans < k){
                start = guess+1;
            }else{
                end = guess-1;
            }
        }
        return start ; //return first occurance of yes
    }
};