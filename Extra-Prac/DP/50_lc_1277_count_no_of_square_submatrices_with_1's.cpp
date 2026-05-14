class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sum = 0;
        vector<int>prev(m,0);
        for(int i = 0;i<n;i++){
            vector<int>curr(m,0);
            for(int j = 0;j<m;j++){
                if(i==0 || j==0){
                    curr[j] = matrix[i][j];
                    sum += curr[j];
                    continue;
                }
                if(matrix[i][j]==1){
                   curr[j] = min(prev[j],min(prev[j-1],curr[j-1])) + 1;
                }else{
                    curr[j] = 0;
                }
                sum += curr[j];
            }
            prev = curr;
        }
        return sum;
    }
};