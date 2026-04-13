class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
       //create adj list
       unordered_map<int,list<pair<int,int>>>adj;
       for(int i = 0 ;i<edges.size();i++){
           int u = edges[i][0];
           int v = edges[i][1];
           int w = edges[i][2];
           adj[u].push_back({v,w});
           adj[v].push_back({u,w});
       }
       //create variabels
       vector<int>weight(V,INT_MAX); //store minimum weight
       vector<int>parent(V,-1);  //store parent of nodes
       vector<bool>MST(V,false); //true for node which included in mst
       //process src
       weight[0]=0;
       parent[0]=-1;
       //loop here
       for(int i= 0;i<V;i++){
            int mini = INT_MAX; //minimum weight
            int u ; //node with minimum weight
           //find minimum weight with MST is false
           //USE MINHEAP FOR REPLACE THIS FOR LOOP
           for(int i = 0 ;i<V;i++){
               if(MST[i] == false && weight[i]<mini){
                    u = i;
                    mini = weight[i];
               }
           }
           //Mark MST of that node is true
           MST[u] = true;
           //choose that node for traverse neighbour and update parent
           for(auto neighbour:adj[u]){
               int node = neighbour.first;
               int nodewt = neighbour.second;
               if(MST[node] == false && nodewt < weight[node]){
                   parent[node] = u;
                   weight[node] = nodewt;
               }
           }
       }
            //Accumulate weight vector and return it
            int ans = 0;
            for(auto num:weight){
                ans += num;
            }
        return ans;
        //we also make adj list of MST by parent vector with node by weight
    }
};