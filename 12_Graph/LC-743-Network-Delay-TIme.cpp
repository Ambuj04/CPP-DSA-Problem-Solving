//Dijsktra Algo
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int wt = top.first;
            if (wt > dist[node])
                continue;
            for (auto nbr : adj[node]) {
                int w = nbr.second;
                int v = nbr.first;
                // relaxation method
                if (dist[v] > wt + w) {
                    dist[v] = wt + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};