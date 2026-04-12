// User function Template for C++
class Solution
{
public:
    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, unordered_map<int, bool> &visited, stack<int> &s, int src)
    {
        visited[src] = true;
        vector<pair<int, int>> v = adj[src];
        for (auto neighbour : v)
        {
            int node = neighbour.first;
            if (!visited[node])
            {
                // not visited
                visited[node] = true;
                dfs(adj, visited, s, node);
            }
        }
        s.push(src);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // adj list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < E; i++)
        {
            int src = edges[i][0];
            int dist = edges[i][1];
            int wt = edges[i][2];
            adj[src].push_back({dist, wt});
        }
        // variables
        unordered_map<int, bool> visited;
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, s, i);
            }
        }
        // stack store topo logical sort
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (dist[node] == INT_MAX)
                continue;
            for (auto neighbour : adj[node])
            {
                int nbr = neighbour.first;
                int nbrwt = neighbour.second;
                //relax method
                if (dist[node] + nbrwt < dist[nbr])
                {
                    dist[nbr] = dist[node] + nbrwt;
                }
            }
        }
        for (int i = 0; i < dist.size(); i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
