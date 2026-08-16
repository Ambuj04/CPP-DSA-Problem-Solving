class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // bellman for relax k+1 times
        for (int i = 0; i <= k; i++) { 
            // copy previous state
            vector<int> temp = dist;
            for (int j = 0; j < flights.size(); j++) {
                int u = flights[j][0];
                int v = flights[j][1];
                int w = flights[j][2];
                // realaxation
                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};