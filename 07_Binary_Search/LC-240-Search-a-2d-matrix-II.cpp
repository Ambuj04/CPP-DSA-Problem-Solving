class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //start from bottom right corner 
        // key idea -> remove wrong row and col and shrink search space
        int row = m-1;
        int col = 0;
        while(row >= 0 && col <= (n-1) ){
            if(matrix[row][col] > target){
                row--;
            }else if(matrix[row][col] < target){
                col++;
            }else{
                return true;
            }
        }
        return false;
    }
};