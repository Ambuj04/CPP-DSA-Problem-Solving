### DAG (Directed Acyclic Graph) = topological order existed
## Which means:
1. No cycles
2. You can process nodes in a linear order
3. You don’t need BFS for shortest path (yes, shocking)
4. Unweighted graph → BFS
5. Weighted DAG → Topo + relaxation (faster than Dijkstra) with negative weight also

| Graph Type        | Algorithm    |
| ----------------- | ------------ |
| Unweighted        | BFS          |
| Weighted + DAG    | Topo + Relax |
| Weighted + cycles | Dijkstra     |
| Negative cycles   | Bellman-Ford |

# BFS thinking:
explore layer by layer
works only if all edges = same weight
ignores weights completely

# DAG thinking:
follow dependency order (topo) general case
use weights properly
never revisit