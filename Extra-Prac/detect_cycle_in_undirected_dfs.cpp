class Solution {
  public:
    void solve(vector<vector<int>>&adj,unordered_map<int,int>&visited, int parent,bool& ans,int num){
        visited[num] = 1;
        for(auto neighbour:adj[num]){
            if(!visited[neighbour]){
                visited[neighbour]=1;
                solve(adj,visited,num,ans,neighbour);
            }else{
                //already visited
                if(parent != neighbour){
                    ans = true;
                    return;
                }
            }
        }
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        //created adj list
        vector<vector<int>>adj(V);
        for(int i = 0;i<edges.size();i++){
            int first = edges[i][0];
            int second = edges[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
            
        }
        //variables declared
       unordered_map<int,int>visited;
       bool ans = false;
       //for multiple components
       for(int i = 0; i < V; i++){
            if(!visited[i]){
                solve(adj,visited,-1,ans,i);
            }
        }

        return ans;
    }
};