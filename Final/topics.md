# Topics on Final Exam
* What an Adelson-Velsky Landis (AVL) tree is.
  * Is a BST that can balance itself.
* How balance factors work in AVL trees.
  * Left height minus right height
* How rotations work in an AVL tree.
  * See my Java implementations.
* How to use rotations to adjust the height of an AVL tree.
  * See my Java implementations.
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
  * Page 598, 599
* How Cormen’s algorithm PRINT-PATH works.
  * It prints out the shortest path from s to v.
* What depth-first search is.
  * Explore the graph as deep as possible before switching to a new branch.
* How Cormen’s algorithms DFS and DFS-VISIT work, and their run times.
  * Theta(V + E)
* What a topological sort is.
  * Find the possible order of nodes that by the time we reach node x, all of the prerequisites for node x has been visited.
* How to use a topological sort to find a sequence of actions.
* How Cormen’s algorithm TOPOLOGICAL-SORT works, and its run time.
  * Call `DFS` on the graph, as each `u.f` is computed, add it to the front of a linked list, then return that linked list when done.
  * Runtime is Theta(E + V) same as `DFS`.
* What a spanning tree is.
* What a minimum-cost spanning tree is.
* What a safe edge is.
  * An edge that does not violate the property of a tree.
* How Cormen’s algorithm GENERIC-MST works (but it’s not really an algorithm).
  * Initialize a set `A` to empty.
  * While `A` does not form a spanning tree.
  * We add a safe edge to `A`.
  * Return `A`.
* What disjoint sets are, as used in graph algorithms.
  * For two set Si and Sj, their intersection is the empty set.
  * Each set is represented by a unique representative element.
  * Every node `x` has a property called `rank` upper bounded on `x`'s height.
* How to represent disjoint sets as forests of trees.
  * The root being the representative element, and the other elements have pointer to the root.
* How the path compression heuristic works.
  * Path compression is done in `FIND-SET` function.
  * We make the first pass up the tree to find the root, then we backtrack and update the `.p` property of each node to point to the root node.
* How the union by rank heuristic works.
  * We point the root of a lower rank node to a higher rank root node.
  * If they have the same rank, we can point either to the other, but we will need to update the rank for the root node.
* How Cormen’s algorithms FIND-SET, LINK, MAKE-SET, and UNION work on forests of trees.
  * `FIND-SET` will return the representative element of a set, and do path compression at the same time.
  * `LINK` will point the root of the lower rank node to the root of the higher rank node.
  * `MAKE-SET` will make a set with the passed elements, and it will point to itself.
  * `UNION` calls `LINK` on two representative elements.
* What a connected component is.
* How Cormen’s algorithm CONNECTED-COMPONENTS works, and its run time.
* How Cormen’s algorithm MST-KRUSKAL works, and its run time.
  * A safe edge is an edge with two vertices in two different disjoint sets.
* What a cycle in a directed graph is.
  * This is pretty much self-explanatory.
* What a single-source shortest path (SSSP) through a directed weighted graph is.
  * Shortest paths.
* How to handle negative, zero, and positive weight cycles when finding an SSSP.
* What relaxation is, when finding an SSSP.
* How Cormen’s algorithms INITIALIZE-SINGLE-SOURCE and RELAX work, and their run times.
  * `INITIALIZE-SINGLE-SOURCE` sets all vertices distance to the source vertex to inf, and set the predecessor of each vertex to `NIL`.
  * It then sets the distance to the source vertex to 0.
  * `RELAX` takes in 3 things, two connected vertices `u` and `v`, and the weight of the edge (`u`, `v`). It is then compare if the distance to `v` is greater than the total of distance to `u` and the weight (`u`, `v`). If this is true, it sets the new distance to `v` to `u.d` + `w(u,v)` and sets the predecessor of `v` to `u`.
* How Cormen’s algorithm BELLMAN-FORD works, and its run time.
  * It will return true if it works, else return false if there is a negative circle.
* How to pronounce the name "Dijkstra."
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
### PRINT-PATH
```
PRINT-PATH(G, s, v):
  if v == s:
    print s
  elif v.pi == NIL:
    print "no path from " s " to " v " exists"
  else:
    PRINT-PATH(G, s, v.pi)
    print v
```
### DFS
```
DFS(G):
  for each vertex u in G.V:
    u.color = WHITE
    u.pi = NIL
  time = 0
  for each vertex u in G.V:
    if u.color == WHITE:
      DFS-VISIT(G, u)

DFS-VISIT(G, u):
  time = time + 1
  u.d = time
  u.color = GRAY
  for each v in G.Adj[u]:
    if v.color == WHITE:
      v.pi = u
      DFS-VISIT(G, v)
  u.color = BLACK
  time = time + 1
  u.f = time
```