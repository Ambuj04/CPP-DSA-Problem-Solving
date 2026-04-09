class Solution {
  public:
    
 bool byDFS(unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&visited,int src,unordered_map<int,bool>&dfsVisited){
        visited[src]=true;
        dfsVisited[src]=true;
        vector<int> v = adj[src];
        for(auto i:v){
            if(!visited[i]){
                if(byDFS(adj,visited,i,dfsVisited)){
                    return true;
                }
            }else{
                //visited and dfsVisited means cycle present
                if(dfsVisited[i]){
                    return true;
                }
            }
        }
        dfsVisited[src] = false;
        return false;
    }
  bool isCyclic(int V, vector<vector<int>> &edges) {
        //create adj list
        unordered_map<int,vector<int>>adj;
        for(int i = 0;i<edges.size();i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
        }
        //declare variable
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        for(int i= 0;i<V;i++){
             if(!visited[i]){
                //by DFS
            if(byDFS(adj,visited,i,dfsVisited)){
                return true;
            }
        }
    }
      return false;
}
};