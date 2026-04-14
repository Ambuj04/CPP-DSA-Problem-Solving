class Solution {
  public:
  void dfs1(int node,stack<int>&s,vector<int>&visited,vector<vector<int>>&adj){
      visited[node]=1;
      for(auto nbr:adj[node]){
          if(!visited[nbr]){
              dfs1(nbr,s,visited,adj);
          }
      }
      //for topo sort
      s.push(node);
  }
  void dfs2(int node,vector<int>&visited,vector<int>&temp,vector<vector<int>>&tadj){
      visited[node]=1;
      temp.push_back(node);
      for(auto nbr:tadj[node]){
          if(!visited[nbr]){
              dfs2(nbr,visited,temp,tadj);
          }
      }
  }
    int kosaraju(int V, vector<vector<int>> &edges) {
       //create adj list
       vector<vector<int>>adj(V);
       for(int i = 0;i<edges.size();i++){
           int u = edges[i][0];
           int v = edges[i][1];
           adj[u].push_back(v);
       }
       stack<int>s;
       vector<int>visited(V,0);
       //step 1 sort all node by discovery time (topo sort)
       for(int i = 0;i<V;i++){
           if(!visited[i]){
               dfs1(i,s,visited,adj);
           }
       }
       /*step 2 transpose the graph (we travel by last node to first node)
       the idea for transpose is if we can reach visited(end to front) graph means strongly
       connected because we can also reach by original graph(front to end).*/
       vector<vector<int>>tadj(V);
       for(int i = 0;i<edges.size();i++){
           int u = edges[i][0];
           int v = edges[i][1];
           tadj[v].push_back(u);
       }
       fill(visited.begin(), visited.end(), 0); //reset visited with 0
       //step 3 now do dfs when you reach visited or no other option to go you are in scc
        vector<vector<int>>ans;
       int count = 0;
       while(!s.empty()){
           int top = s.top();
           s.pop();
           if(!visited[top]){
               count++;
               vector<int>temp;
               dfs2(top,visited,temp,tadj);
               ans.push_back(temp);
           }
       }
    //   for(auto v:ans){
    //       for(auto i:v){
    //           cout<<i<<" ";
    //       }
    //       cout<<endl;
    //   }
        return count;
    }
};