// User function Template for C++
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
      vector<int>dist(V,1e8); 
      dist[src] = 0; //only found cycle which nodes are connected with src
        //run n-1 times relaxation in all edges
        for(int i = 0;i < V-1;i++){
            for(int j = 0;j<edges.size();j++){
                int u = edges[j][0];
                int v= edges[j][1];
                int w= edges[j][2];
                //realaxation
                if(dist[u] != 1e8 && dist[u]+w < dist[v]){
                    dist[v] = dist[u]+w;
                }
            }
        }
        //one more time
        for(int j = 0;j<edges.size();j++){
                int u = edges[j][0];
                int v= edges[j][1];
                int w= edges[j][2];
                //realaxation
                if(dist[u] != 1e8 && dist[u]+w < dist[v]){
                    //negative cycle found means no shortest dist available
                   return {-1};
                }
        }
            return dist;
    }
};
