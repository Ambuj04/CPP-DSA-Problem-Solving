class Solution {
  public:
  void solve(vector<vector<int>>&adj,vector<int>& ans,unordered_map<int,int>&visited,int num){
    
    //base case 
    if(visited[num]){
        return;
    }
    
    //processing 
    ans.push_back(num);
    visited[num]=1;
    
    //recursion
   vector<int> v = adj[num];
   for(int i:v){
       solve(adj,ans,visited,i);
   }
    
     
      
      
      
  }
    vector<int> dfs(vector<vector<int>>& adj) {
      vector<int>ans;
      unordered_map<int,int>visited;
      solve(adj,ans,visited,0);
      return ans;
        
    }
};