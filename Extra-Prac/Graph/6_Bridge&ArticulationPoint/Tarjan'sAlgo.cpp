class Solution {
public:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& visited,vector<vector<int>>& adj, vector<int>& time,vector<int>& low, vector<vector<int>>& bridges) {
        visited[node] = 1;
        // travel node first time
        time[node] = low[node] = timer++;
        for (auto nbr : adj[node]) {
            if (nbr == parent) {
                // back edge to parent
                continue;
            }
            if (!visited[nbr]) {
                // not visited
                dfs(nbr, node, visited, adj, time, low, bridges);
                // return back from dfs,update low from neighbour(because that ells us if we remove the discovery time we have another low time which i reach to that node means not a single path)
                low[node] = min(low[node], low[nbr]);
                if (low[nbr] > time[node]) {
                    // brige present
                    bridges.push_back({nbr, node});
                }
            } else {
                // visited
                low[node] = min(low[node], low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,vector<vector<int>>& connections) {
        // adj list
        vector<vector<int>> adj(n);
        for (auto vec : connections) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // variables
        vector<int> visited(n, 0);
        vector<int> time(n); // discovery time
        vector<int> low(n);  // lowest visited time without parent consideration
        vector<vector<int>> bridges;
        // dfs
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, adj, time, low, bridges);
            }
        }
        return bridges;
    }
};