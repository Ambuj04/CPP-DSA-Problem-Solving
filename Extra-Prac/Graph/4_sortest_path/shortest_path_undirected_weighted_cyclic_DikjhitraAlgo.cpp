class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        set<pair<int, int>> st; // also use heap
        st.insert({0, src});
        while (!st.empty())
        {
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            st.erase(st.begin());
            for (auto neighbour : adj[topNode])
            {
                if (nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    auto record = st.find({dist[neighbour.first], neighbour.first});
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    st.insert({dist[neighbour.first], neighbour.first});
                }
            }
        }
        return dist;
    }
};