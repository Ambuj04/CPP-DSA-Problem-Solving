class Solution {
public:
    bool issafe(int r,int c,int n,int m){
        if(r < 0 || c < 0 || r >= n || c >= m){
            return false;
        }
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        //By Dijsktra's Algo
        int x[] = {-1,0,1,0}; //for 4 direction movement
        int y[] = {0,1,0,-1};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>pq;
        effort[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int nodeEffort = top.first;
            int r = top.second.first;
            int c = top.second.second;
            if(effort[r][c] < nodeEffort){
                continue;
            }
            if(r == n-1 && c == m-1){
                return effort[r][c];
            }
            for(int i = 0;i<4;i++){
                int row = r+x[i];
                int col = c+y[i];
                if(issafe(row,col,n,m)){
                    int currEffort = abs(heights[row][col]-heights[r][c]);
                    int newEffort = max(currEffort,nodeEffort);
                    //relaxation method
                    if(effort[row][col] > newEffort){
                        effort[row][col] = newEffort;
                        pq.push({effort[row][col],{row,col}});
                    }
                }
            }           
        }
       return effort[n-1][m-1];
    }
};