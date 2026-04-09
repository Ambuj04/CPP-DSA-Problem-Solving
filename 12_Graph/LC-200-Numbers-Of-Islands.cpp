//ALSO DONE BY BFS
class Solution {
public:
    //up down left right
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    bool valid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>= n || j>=m) return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid,int n,int m,int i,int j,vector<vector<char>>&visited){
        visited[i][j] = '1';
        for(int k = 0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];
            if(valid(row,col,n,m) &&  grid[row][col]=='1' && visited[row][col]=='0'){
                dfs(grid,n,m,row,col,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<char>>visited(n,vector<char>(m,'0'));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j] == '0'){
                    dfs(grid,n,m,i,j,visited);
                    res++;
                }
            }
        }
        return res;
    }
};