## Spanning Tree 

1. Convert Graph into tree which contains n nodes and n-1 edges
2. every node is reachable by another node

## Minimum Spanning Tree

1. Minimum cost of weights

## Prim's Algo

Core rule of Prim’s Algorithm :
Only update nodes that are not yet included in MST

## Kruskal's Algo

First create disjoint set
sort with weights
check if both node is from same parent or not
if both node is from different parent add their wt in answer and perform union
in union we don't need to find parent again bcz we already find ultimate parent in loop