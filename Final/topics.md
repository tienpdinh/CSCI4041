# Topics on Final Exam
* What an Adelson-Velsky Landis (AVL) tree is.
* How balance factors work in AVL trees.
* How rotations work in an AVL tree.
* How to use rotations to adjust the height of an AVL tree.
* How Cormen’s algorithm HUFFMAN works, and its run time.
  * It is a greedy algorithm, it starts by maintaining a min priority queue, then continuously extracting the queue and merge the tree in n-1 steps.
  * Pseudocode for `HUFFMAN` is below.
  * Runtime is O(nlgn), see full analysis page 433.
* The formal definition of a graph G = ⟨V, E⟩.
  * I'm making this up: A graph consists of a set of vertices and a set of edges that connect the vertices.
* What directed and undirected graphs are.
  * No can do.
* What a weighted graph is.
  * Edges have weights in them.
* The adjacency list representation for graphs (G.Adj).
  * Each entry in the list represent a vertex, and this entry will have the vertices that this vertex has connections to.
* The adjacency matrix representation for graphs (G.M).
  * Dim of this matrix is `num_ver` by `num_ver`. Connections are from rows to columns.
* What breadth-first search is.
  * Explore all branches before going deeper.
* How Cormen’s algorithm BFS works, and its run time.
  * Pseudocode is below
  * Complexity analysis is in page 597.
  * Runtime is O(V+E)
* What a path through a graph is.
  * A path through two vertices is "a path", if there is no path, the distance will be inf.
* What a shortest path through an unweighted graph is.
  * The minimum number of edges that we can go in order to reach the destination vertex from the source vertex.
* How to use BFS to find a shortest path.
* How Cormen’s algorithm PRINT-PATH works.
* What depth-first search is.
* How Cormen’s algorithms DFS and DFS-VISIT work, and their run times.
* What a topological sort is.
* How to use a topological sort to find a sequence of actions.
* How Cormen’s algorithm TOPOLOGICAL-SORT works, and its run time.
* What a spanning tree is.
* What a minimum-cost spanning tree is.
* What a safe edge is.
* How Cormen’s algorithm GENERIC-MST works (but it’s not really an algorithm).
* What disjoint sets are, as used in graph algorithms.
* How to represent disjoint sets as forests of trees.
* How the path compression heuristic works.
* How the union by rank heuristic works.
* How Cormen’s algorithms FIND-SET, LINK, MAKE-SET, and UNION work on forests of trees.
* What a connected component is.
* How Cormen’s algorithm CONNECTED-COMPONENTS works, and its run time.
* How Cormen’s algorithm MST-KRUSKAL works, and its run time.
* What a cycle in a directed graph is.
* What a single-source shortest path (SSSP) through a directed weighted graph is.
* How to handle negative, zero, and positive weight cycles when finding an SSSP.
* What relaxation is, when finding an SSSP.
* How Cormen’s algorithms INITIALIZE-SINGLE-SOURCE and RELAX work, and their run times.
* How Cormen’s algorithm BELLMAN-FORD works, and its run time.
* How to pronounce the name ‘‘Dijkstra.’’
* How Cormen’s algorithm DIJKSTRA works, and its run time.

## Pseudocode
### HUFFMAN
```
// Example for HUFFMAN is in page 432
HUFFMAN(C):
  n = |C|		// Cardinality of C
  Q = C			// The priority queue initialized with C
  for i=1 to n-1:
    allocate a new node z
    z.left = x = EXTRACT-MIN(Q)
    z.right = y = EXTRACT-MIN(Q)
    z.freq = x.freq + y.freq
    INSERT(Q, z)
  return EXTRACT-MIN(Q)	// returns the root of the tree
```
### Breadth First Search
```
BFS(G, s):
  for u in G.V:
    u.color = WHITE
    u.d = inf
    u.pi = NIL
  s.color = GRAY
  s.d = 0
  s.pi = NIL
  Q = EMPTY-QUEUE	// Initialize an empty first in first out queue
  ENQUEUE(Q, s)
  while Q not empty:
    u = DEQUEUE(Q)
    for v in G.Adj[u]
      if v.color == WHITE:
        v.color = GRAY
	v.d = u.d + 1
	v.pi = u
	ENQUEUE(Q, v)
    u.color = BLACK
```
* `WHITE` is not visited, `GRAY` is partially visited, and `BLACK` is completedly visited.
* `d` is the distance between the start vertex to the current vertex.
* `pi` is the predecessor of the current vertex.