/* 
Find Topological Sort (Kahn's Algo)
Step 1 Find indegree of all node
Step 2 Push 0 indegree in queue
Step 3 Push node which remove from queue to answer
Step 4 Repeat Step 1 and Step 2 for the removed node
*/
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //adj list
        unordered_map<int,list<int>>adj;
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        //find indegress
        vector<int>indegree(V);
        for(auto i:adj){
          for(auto j:i.second){
              indegree[j]++;
          }  
        }
        //0 indegree push in queue
        queue<int>q;
        for(int i = 0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //do bfs
        vector<int>ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            //ans store
            ans.push_back(front);
            //neighbour indegree update
            for(auto neighbour:adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};