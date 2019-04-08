# Proving the Optimal Substructure

1. Prove that the problem has the **greedy choice property** which says that the first step (call it _g_) taken by the greedy algorithm part of _some_ optimal solution. This is typically done using a proof by contradiction in which some arbitrary optimal solution _S_ that doesn't include _g_ is modified to create a solution _S'_ that include _g_. It is very important to prove that _S'_ is a legal solution and that _S'_ is at least as good as _S_.

2. Prove that the problem has the **optimal substructure property**. Namely, let _P_ be the original problem to be solved, let _g_ be the first step taken by the greedy algorithm, and let _S_ be an optimal solution for _P_ that includes _g_ (which by the greedy choice property must exist). The problem has the optimal substructure property if
   * There exists a subproblem _P'_ of _P_ that remains after _g_ is included in the greedy solution. Be careful in this step that you truly have a subproblem. Think of defining your problem via the parameters of a recursive procedure. Now define _P'_ by a recursive call. If you want to add any extra constraints then you need to generalize the form of the problem (i.e. add additional parameters). If you do this, then you have to go back and prove that the greedy choice property holds for this general problem form.
   * _P'_ is optimally solved in S. That is, the solution for _P'_ contained within _S_ is optimal for _P'_. To do this it is best to express the value of _S_ as some function that depends on the value of the optimal solution _S'_ for _P'_ and parameters of the problem. Then argue that _P'_ is optimally solved within _S_.

[Source](https://www.cse.wustl.edu/~sg/CSE441_FL04/greedy-methodology.pdf)
[Example](https://www.coursera.org/lecture/algorithms-greedy/proof-of-optimal-substructure-0qjbs)