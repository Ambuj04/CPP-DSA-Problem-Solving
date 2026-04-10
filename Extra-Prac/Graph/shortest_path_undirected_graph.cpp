#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
//for path array use parent, but for distance parent array is unnecassary because bfs do this for us in free.
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<int>dist(V,-1);
       //adjlist
       unordered_map<int,list<int>>adj;
       for(int i = 0;i<edges.size();i++){
           int u = edges[i][0];
           int v = edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }     
        //do bfs (we explore layer by layer and is automatic gives shortest path)
       queue<int>q;
           q.push(src);
            dist[src]=0;
           while(!q.empty()){
               int front = q.front();
               q.pop();
               for(auto neighbour:adj[front]){
                    if(dist[neighbour]==-1){
                        dist[neighbour] = dist[front]+1;
                        q.push(neighbour);
                    }
               }
            }
       return dist;
    }
};
