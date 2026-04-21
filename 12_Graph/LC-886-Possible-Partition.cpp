class Solution
{
public:
    bool flag = true;
    void dfs(unordered_map<int, vector<int>> &adj, int node, int color,
             vector<int> &colors)
    {
        colors[node] = color;
        for (int nbr : adj[node])
        {
            if (colors[nbr] != -1 && colors[nbr] == color)
            {
                // contradiction
                flag = false;
            }
            if (colors[nbr] == -1)
            {
                dfs(adj, nbr, 1 - color, colors);
            }
        }
        return;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> colors(n, -1);
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < dislikes.size(); i++)
        {
            // 1 based indexing into 0 basec indexing
            int u = dislikes[i][0] - 1;
            int v = dislikes[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
            {
                dfs(adj, i, 0, colors);
            }
        }
        return flag;
    }
};