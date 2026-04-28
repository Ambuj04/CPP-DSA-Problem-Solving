//shortest path in weighted graph
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d>dist[node]){
                continue;//ignore old value
            }
            for(auto p:adj[node]){
                int neighbour = p.first;
                int wt = p.second;
                if(wt + d < dist[neighbour]){
                    dist[neighbour] = d + wt;
                    pq.push({wt + d,neighbour});
                }
            }
        }
            return dist;
    }
};