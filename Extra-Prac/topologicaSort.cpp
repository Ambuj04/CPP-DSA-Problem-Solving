class Solution {
  public:
    void dfs(unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&visited,stack<int>&s,int src){
        
        visited[src] = true;
        vector<int> v = adj[src];
        for(auto neighbour:v){
            if(!visited[neighbour]){
                 //not visited
                 visited[neighbour] = true;
                 dfs(adj,visited,s,neighbour);
            }
        }
        s.push(src);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //adj list
        unordered_map<int,vector<int>>adj;
        for(int i = 0;i<edges.size();i++){
            int src = edges[i][0];
            int dist = edges[i][1];
            adj[src].push_back(dist);
        }
        //variables
        unordered_map<int,bool>visited;
        stack<int>s;
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,s,i);
            }
        }
        vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top()) ;
        s.pop();
    }
      return ans;  
    }
};