// User function Template for C++
class Solution {
  public:
  //static keyword is must in cmp when work with sort
  static bool cmp(vector<int>&a,vector<int>&b){
      return a[2] < b[2];
  }
  void make_set(vector<int>&parent,int V){
      for(int i = 0 ;i < V;i++){
          //at starting each node is parent of self
          parent[i]=i;
      }
  }
  int find_parent(vector<int>&parent,int node){
      if(parent[node]==node){
          return node;
      }
      return parent[node] = find_parent(parent,parent[node]); //with path compresion
  }
  void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
    //because we only find ultimate parent inside loop . we don't need to find parent again
      if(rank[u] < rank[v]){
          parent[u] = v;
      }else if(rank[u] > rank[v]){
          parent[v] = u;
      }else{
          parent[u] = v; //random
          rank[v]++;
      }
  }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<int>parent(V,-1);
        vector<int>rank(V,0);
        int minWt = 0;
        //create set
        make_set(parent,V);
        //sort with minimum weights
        sort(edges.begin(),edges.end(),cmp);//for ascending wt
        //process one by one
        for(int i = 0;i<edges.size();i++){
            //check if both belong to same or diff compenent
            int u = find_parent(parent,edges[i][0]);
            int v = find_parent(parent,edges[i][1]);
            int wt = edges[i][2];
            if(u != v){
                //do union of node
                unionSet(u,v,parent,rank);
                //add weight when make connection
                minWt += wt;
            }
        }
       return minWt; 
    }
};