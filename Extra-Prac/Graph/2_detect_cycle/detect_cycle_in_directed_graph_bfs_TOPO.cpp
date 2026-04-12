class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // adj list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        // find indegress
        vector<int> indegree(V);
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }
        // 0 indegree push in queue
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // do bfs
        int count = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            count++;
            // neighbour indegree update
            for (auto neighbour : adj[front])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        if (count == V)
        {
            // cycle not present
            return false;
        }
        else
        {
            return true;
        }
    }
};