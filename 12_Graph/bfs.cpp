class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int>q;
        vector<int>ans;
        unordered_map<int,bool>visited;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto num:adj[node]){
                if(visited[num] == false){
                    q.push(num);
                    visited[num] = true;
                }
            }
            
        }
      
        return ans;
        
    }
};