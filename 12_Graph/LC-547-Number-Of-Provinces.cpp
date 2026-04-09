// By BFS but we can do both BFS and DFS
class Solution {
public:
    void bfs(vector<vector<int>>& adj, int src, queue<int>& q,
             vector<int>& visited) {
        q.push(src);
        visited[src] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
    }
    void dfs(vector<vector<int>>& adj, int src, vector<int>& visited) {
        visited[src] = 1;
        for (auto neighbour : adj[src]) {
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                dfs(adj, neighbour, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        queue<int> q;
        vector<vector<int>> adj(n);
        vector<int> visited(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // not visited
                bfs(adj,i,q,visited);
                // dfs(adj, i, visited);
                res++;
            }
        }
        return res;
    }
};