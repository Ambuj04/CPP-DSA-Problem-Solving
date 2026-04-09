class Solution {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    bool valid(int i,int j,int n,int m){
        if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int time = 0;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh>0){
            time++;
            int s = q.size();
            while(s--){
                pair<int,int> coordinate = q.front();
                int i = coordinate.first;
                int j = coordinate.second;
                q.pop();
                for(int k=0;k<4;k++){
                    int row = i+x[k];
                    int col = j+y[k];
                    if(valid(row,col,n,m) && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col] = 0;
                        fresh--;
                    }
                }
            }
        }
        if(fresh>0) return -1;
        return time;
    }
};