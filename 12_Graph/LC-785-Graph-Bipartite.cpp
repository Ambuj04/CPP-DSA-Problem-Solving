class Solution
{
public:
    bool flag = true;
    void dfs(vector<vector<int>> &graph, int node, int color,
             vector<int> &colors)
    {
        colors[node] = color;
        for (int nbr : graph[node])
        {
            if (colors[nbr] != -1 && colors[nbr] == color)
            {
                // contradiction
                flag = false;
            }
            if (colors[nbr] == -1)
            {
                dfs(graph, nbr, 1 - color, colors);
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
            {
                dfs(graph, i, 0, colors);
            }
        }
        return flag;
    }
};
// 1-color is fo 0 to 1 and 1 to 0