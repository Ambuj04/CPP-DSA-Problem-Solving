Bellman Ford tell's us negative cycle present of not.
if negative cycle is not present then it also tells us shortest distance.
Bellman ford apply in directed graph.
IF we need to finde -ve cylce in undirected graph then convert undirected graph into directed graph.

apply n-1 times this formula in all edges (edges in any order)
//distance minimizaiton formula
if(dist[u]+wt<dist[v]>){
    dist[v] = dist[u]+wt
}
apply one last time -> if any distance is updated then you can't find shortest node
if dist not update then return shortest path

Negative wt or edges is allowed by negative cycle not allowed
if negative cycle found means no shortest dist available