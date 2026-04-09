class Solution {
  public:
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
       queue<int>q;
       unordered_map<int,int>parent;
       //for multiple components
       for(int i = 0; i < V; i++){
            if(!visited[i]){
                       //push first element
       q.push(i);
       visited[i] = 1;
       parent[i] = -1;
        while(!q.empty()){
        int temp = q.front();
        q.pop();
        vector<int> v = adj[temp];
            for(auto i:v){
                //process adj elements
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                    parent[i]=temp;
                }else{
                    //I find a visited node that is not my parent
                    if( i != parent[temp]){  
                     //cycle detected
                        return true;
                    }
                }
            }
        }
            }
        }

        return false;
    }
};