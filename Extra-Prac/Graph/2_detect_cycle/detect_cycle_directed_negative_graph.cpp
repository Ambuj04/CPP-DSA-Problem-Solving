class Solution {
  public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<int>dist(n,0); //0 initialize detectcycle in any place in graph (all node act as source)
        //run n-1 times relaxation in all edges
        for(int i = 0;i < n-1;i++){
            for(int j = 0;j<edges.size();j++){
                int u = edges[j][0];
                int v= edges[j][1];
                int w= edges[j][2];
                //realaxation
                if( dist[u]+w < dist[v]){
                    dist[v] = dist[u]+w;
                }
            }
        }
        //one more time
        int isNegWtCycle = 0;
        for(int j = 0;j<edges.size();j++){
                int u = edges[j][0];
                int v= edges[j][1];
                int w= edges[j][2];
                //realaxation
                if(dist[u]+w < dist[v]){
                    //negative cycle detect
                    isNegWtCycle = 1;
                }
        }
        return isNegWtCycle;
    }
};