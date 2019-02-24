# Midterm 1 Topics
## Tuesday, Feb 26, 2019
 * Read the syllabus (for bonus question).
 * Mathematics from prerequisite courses.
 * What a recurrence is.
   * Recurrence is when an algorithm repeatedly calls itself (I guess)
 * How to solve recurrences in simple special cases.
   * Problem 2.3-3 in Cormen's text (page 39), solve using mathematical induction. Check [solution](https://www.chegg.com/homework-help/Introduction-to-Algorithms-3rd-edition-chapter-2.3-problem-3E-solution-9780262033848).
 * Formal definitions of O, Θ, Ω.
   * This should be in your notebook (if you take note during class)
   * Cormen's page 44.
 * How to prove that an expression is in O(e), Θ(e), Ω(e).
   * The mothod generally is to find a constant C and a bound for n.
 * What a divide and conquer algorithm is.
   * Errrm, divide and conquer, literally.
 * The parts of a divide and conquer algorithm: divide, conquer, combine.
 * How the Python function mergesort works, and its run time.
   * I'm gonna implement this.
 * How the run time of a divide and conquer algorithm can be expressed as a recurrence.
 * What the Master Theorem is.
 * How to solve recurrences using the Master Theorem.
   * Look in the [recitation](https://www.evernote.com/shard/s626/client/snv?noteGuid=39b6e39a-91c2-4200-b3bd-ea2e2c2dd61b&noteKey=132c8adbf32370cf&sn=https%3A%2F%2Fwww.evernote.com%2Fshard%2Fs626%2Fsh%2F39b6e39a-91c2-4200-b3bd-ea2e2c2dd61b%2F132c8adbf32370cf&title=4041%2BRecitation%2BContent)
 * What a loop invariant is.
 * How to prove an algorithm correct using a loop invariant.
 * The three parts of such a proof: initialization, maintenance, termination.
 * What a backtracking algorithm is.
   * [Here](https://www.geeksforgeeks.org/backtracking-algorithms/)
 * The parts of a backtracking algorithm: base case, make a decision, explore the decision, unmake the decision.
 * What continuation passing is.
   * Not in Cormen's text.
 * How the Python function permute works, and its run time.
 * What a binary tree is.
 * Binary tree terminology: child, edge (link), empty tree, height (in terms of edges), internal node, external (leaf) node, left child, node (vertex), right child, root, parent, etc.
 * What a complete binary tree is.
 * What a nearly complete binary tree is.
 * How to represent a nearly complete binary tree as an array.
 * How to use ∞ and −∞ in algorithms.
 * What a max-heap is.
 * What a min-heap is.
 * What a priority queue is.
 * How to implement the `DEQUEUE`, `ENQUEUE`, `IS-EMPTY`, and `IS-FULL` operations for priority queues using max-heaps.
 * You must also understand how these algorithms work (from Cormen’s text), and their run times.
```
BUILD-MAX-HEAP  
HEAP-EXTRACT-MAX  
HEAP-INCREASE-KEY  
HEAP-MAXIMUM  
HEAPSORT  
INSERTION-SORT  
LEFT  
MAX-HEAP-INSERT  
MAX-HEAPIFY  
PARENT  
RIGHT
```


## Won't ask
 * Definition questions.

## Ask
 * Do? Runtime? Proof for runtime for an algorithm in Cormen's text.
 * Fixing algorithm.
 * Prove some expression is in Big O of something.
 * Write an algorithm.