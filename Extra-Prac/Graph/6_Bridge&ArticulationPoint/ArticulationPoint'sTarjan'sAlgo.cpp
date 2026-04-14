class Solution {
  public:
  int timer = 0;
  void  dfs(int node,int parent,vector<int>&time,vector<int>&low,vector<int>&visited,vector<vector<int>>&adj,vector<int>&points){
      visited[node]=1;
      int child = 0;
      time[node] = low[node] = timer++;
      for(auto nbr:adj[node]){
          if(nbr == parent) continue;
          if(!visited[nbr]){
              dfs(nbr,node,time,low,visited,adj,points);
              low[node] = min(low[nbr],low[node]);
              if(low[nbr]>=time[node] && parent != -1){
                  points[node]= 1;
              }
              child++;
          }else{
               low[node] = min(low[node], time[nbr]);
          }
      }
      if(parent == -1 && child>1){
          points[node] = 1;
      }
  };
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        //create adj list
        vector<vector<int>>adj(V);
        for(int i = 0; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //varibles
        vector<int>time(V);
        vector<int>low(V);
        vector<int>visited(V);
        vector<int>points(V,0);
        //dfs
        for(int i = 0 ;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,time,low,visited,adj,points);
            }
        }
        vector<int>ans;
        bool ansfound = false;
        for(int i =0;i<V;i++){
           if(points[i]>0){
               ans.push_back(i);
               ansfound = true;
           }
        }
        if(!ansfound){
            ans.push_back(-1);
        }
        return ans;
    }
};