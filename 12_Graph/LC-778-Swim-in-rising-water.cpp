class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //By Dijsktra's Algo
        int x[] = {-1,0,1,0}; //for 4 direction movement
        int y[] = {0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>maxTime(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>pq;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        maxTime[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int time = top.first;
            int r = top.second.first;
            int c = top.second.second;
            if(vis[r][c]) continue;
                vis[r][c] = true;
            if(maxTime[r][c] < time){
                continue;
            }
            if(r == n-1 && c == m-1){
                return maxTime[r][c];
            }
            for(int i = 0;i<4;i++){
                int row = r+x[i];
                int col = c+y[i];
                if(row >= 0 && col >= 0 && row < n && col < m){
                    int currTime = grid[row][col];
                    int maxCurrTime = max(currTime,time);
                    //relaxation method
                    if(maxTime[row][col] > maxCurrTime){
                        maxTime[row][col] = maxCurrTime;
                        pq.push({maxTime[row][col],{row,col}});
                    }
                }
            }           
        }
       return maxTime[n-1][m-1];
    }
};