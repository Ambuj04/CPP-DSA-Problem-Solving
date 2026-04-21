class Solution {
  public:
  int rec(int day,int last,vector<vector<int>>&points){
      //TC -> O(3^n)
      //SC -> O(n)
      if(day == 0){
          int maxPoint = 0;
          for(int task = 0;task<3;task++){
              if(task!=last){
                  maxPoint = max(maxPoint,points[day][task]);
              }
          }
          return maxPoint;
      }
      int  maxPoints = 0;
      for(int task = 0;task<3;task++){
          if(task !=last){
              int point = points[day][task] + rec(day-1,task,points);
              maxPoints = max(maxPoints,point);
          }
      }
      return maxPoints;
  }
  int mem(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
      //TC -> O(n * 4 * 3)
      //SC -> O(n * 4) + O(n)
      if(day == 0){
          int maxPoint = 0;
          for(int task = 0;task<3;task++){
              if(task!=last){
                  maxPoint = max(maxPoint,points[day][task]);
              }
          }
          return maxPoint;
      }
      if(dp[day][last] != -1){
          return dp[day][last];
      }
      int  maxPoints = 0;
      for(int task = 0;task<3;task++){
          if(task !=last){
              int point = points[day][task] + mem(day-1,task,points,dp);
              maxPoints = max(maxPoints,point);
          }
      }
      return dp[day][last] = maxPoints;
  }
  int tab(vector<vector<int>>&points){
      //TC -> O(n * 4 * 3)
      //SC -> O(n*4)
      int n = points.size();
      vector<vector<int>>dp(n,vector<int>(4,-1));
      dp[0][0] = max(points[0][1],points[0][2]);
      dp[0][1] = max(points[0][0],points[0][2]);
      dp[0][2] = max(points[0][0],points[0][1]);
      dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));

    for(int day = 1; day < n;day++){
        for(int last = 0 ; last < 4;last++){
            dp[day][last] = 0;
            for(int task = 0;task<3;task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
      return dp[n-1][3];
  }
  int so(vector<vector<int>>&points){
      //TC -> O(n * 4 * 3)
      //SC -> O(4)
      int n = points.size();
      vector<int>prev(4),curr(4);
      prev[0] = max(points[0][1],points[0][2]);
      prev[1] = max(points[0][0],points[0][2]);
      prev[2] = max(points[0][0],points[0][1]);
      prev[3] = max(points[0][0],max(points[0][1],points[0][2]));

    for(int day = 1; day < n;day++){
        for(int last = 0 ; last < 4;last++){
            curr[last] = 0;
            for(int task = 0;task<3;task++){
                if(task != last){
                    int point = points[day][task] + prev[task];
                    curr[last] = max(curr[last],point);
                }
            }
        }
        prev = curr;
    }
      return prev[3];
  }
    int maximumPoints(vector<vector<int>>& mat) {
        int ans;
        int n = mat.size();
        // ans = rec(n-1,3,mat);
        vector<vector<int>>dp(n,vector<int>(4,-1));// 4 becase we indroduce 3 when we do nothing and day-1 we can do 0 1 2.
        // ans = mem(n-1,3,mat,dp);
        // ans = tab(mat);
        ans = so(mat);
        return ans;
    }
};