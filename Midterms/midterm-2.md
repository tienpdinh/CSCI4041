# Topics for 2nd Midterm
## Tuesday, April 9, 2019
* What a hash table is.
  * Hash table is an effective data structure to implement dictionary that often results in O(1) search time.
* What a hash function is.
  * Hash function maps the universe U of keys into the slots of a hash table T[0..m-1].
* The division method (with mod) for designing hash functions. (Section 11.3.1)
  * h(k) = k mod m. We map a key k into one of m slots by taking the remainder of k divided by m.
  * Could be used for simple uniform hashing.
* What a hash modulus is, and how to choose one.
  * What is this?
* What a hash table collision is.
  * When the hash function generates the same slot for different keys.
* What simple uniform hashing is.
  * Is when the probability of the hash functions generating different keys are distributed equally among all slots.
  * Pr{h(k) = j} = 1/M. M is the total slots of the hash table, 0 <= j < M.
  * The best case is when the key is the first element in the bucket O(1).
  * Worst case is when all keys go to the same bucket O(n).
  * Average case depends on how well the hash function distributes keys among buckets.
  * For an unsuccessful search, k is not in the table, each bucket is equally likely to be searched, avg runtime will be Θ(α + 1) where the 1 is the cost of h(k).
  * The avg runtime is the same for a successful search, a full proof of this is in the notebook, involves probability and expected values.
* How to resolve collisions in a hash table by chaining.
  * The idea of buckets, each bucket contains a linked list, a hash table with M elements has M buckets.
* What the load factor α is.
  * Assuming we have M buckets in a hash table, and we have a total of n possible keys that we need to hash. Load factor is defined as n/M, the average number of elements in each bucket.
* What an expected value is.
  * The sum of each possible value multiplied by its probability in a sample space.
* Linearity, and other rules for manipulating expected values.
* What a random variable is.
* What the expected search time is for a chained hash table under simple uniform hashing.
  * Defined above.
* What probing is (Cormen calls it open addressing). (Section 11.4)
  * In probing, each key gets its own slot in the hash table, in other words, this is to guarantee a load factor of 1.
  * Insert and search algorithms are in the notebook.
* What uniform hashing is (different from simple uniform hashing).
  * Page 271.
  * The probe sequence of each key is equally likely to be any of the m! permutations of (0..m-1). Uniform hashing produces a whole probe sequence for a single key (unlike simple uniform hashing which generates only one value for each key).
* What clustering is.
  * Defining below.
* Strategies for probing: linear probing, quadratic probing, double hashing.
  * Linear probing:
    * Given an ordinary hash function h' (axuliary hash function), linear probing hash function is defined as h(k,i) = h(h'(k)+i) mod M.
    * We linearly probe each slot starting from the given slot i.
    * Easy to implement, but suffers from clustering, in which an empty slot is followed by a sequence of occupied slots, increasing the average search time. (Primary clustering).
  * Quadratic probing:
    * Hash function is h(k,i) = (h'(k) + c1i + c2i^2) mod M.
    * If two keys have the same initial probe position, then their probe sequences are the same. This is called secondary clustering.
  * Double hashing
    * Double hashing offers one of the best methods available for open addressing.
    * h(k,i) = (h1(k) + ih2(k)) mod m.
    * h1 and h2 are auxiliary functions
    * The value of h2(k) must be relatively prime to the hash table size M for the entire hash table to be searched.
    * One way is to make the size a power of 2 and to design h2 so that it always produce odd numbers.
    * Another way is to make m prime and design h2 so that it always return a positive integer less than m.
      * h1(k) = k mod m
      * h2(k) = 1 + (k mod m')
      * whereas m is prime and m' is slightly less than m, say m - 1.
* What a Binary Search Tree (BST) is (as discussed in lecture).
  * If k1, k2 are keys, then exactly one one of these is true:
    * k1 > k2
    * k1 = k2
    * k1 < k2
  * In other words, BST has keys that are ordered.
* How to add a key/value pair to a BST.
  * Recursively visit left and right children of the nodes until there is no child, the inserted node should be a leaf node.
* How to find the value that corresponds to a key in a BST.
  * Check if the key is found at the current node.
  * Recursively visit left or right children of the nodes until you found the node, or until you reach NULL, which indicates the key doesn't exist in the tree.
* How to delete a key/value pair from a BST.
  * Case 0: Deleting a leaf node, we simply set its parent pointer to NULL.
  * Case 1: Deleting a node with only one child, we simply set its parent pointer to that one child.
  * Case 2: Deleting a node with two children, we either have to search for the maximum key in the left child, or the minimum key in the right child, then we swap the data between the node to be deleted and the found node, then we proceed to delete the max key in the left subtree, or min key in the right subtree.
* What a balanced BST is.
  * If hl is the height of the left subtree, and hr is the height of the right subtree, then | hl - hr | <= 1.
* What an unbalanced BST is.
  * Really...
* Run times of BST algorithms for add, find, delete.
  * Should be O(logn) (The height of the tree with n total elements)
* What memoization is.
  * Stores intermediate results in a table.
* What top-down and bottom-up memoization is.
  * Top-down: we solve the problem using the usual recursive way, however, we store result of each subproblem in a table, so that when we are asked again for that problem, we can get the value from the table instead of having to calculate that subproblem again.
  * We put all the subproblems in a sorted manner, then we solve them from the bottom up, so that when we are asked for a preceding problem, we know we have solved all of the prerequisite problems.
* How the Fibonacci example (from lecture) uses memoization.
  * Top-down: We use the usual recursive way, but before we try to solve an subproblem, we search the table to see if it has already been solved.
  * Bottom-up: We use an array to store the values of f(0) -> f(n), we keep doing that until we reach f(n).
* What Dynamic Programming (DP) is.
  * DP divides the problem into smaller overlapping subproblem, storing the solutions to the subproblem in a table, hence it is doing less work than Divide and Conquer.
* How memoization is like DP.
  * Storing subproblem...
* What an Optimal Binary Search Tree (OBST) is.
  * An OBST minimizes the expected search cost.
* What success nodes (k’s) and failure nodes (d’s) are.
  * Success nodes are internal nodes whereas failure nodes are external nodes.
  * The number of failure nodes is one greater than the number of success nodes.
* How probabilities of these nodes (p’s and q’s) work.
  * All the probabilities should sum up to 1, we do not deal with deletions.
* What an expected value is.
* How to compute the expected value of search in an OBST.
* How to generate all possible OBST’s for a sorted list of keys.
* How Cormen’s algorithm OPTIMAL-BST works.
* How OPTIMAL-BST uses the arrays e, w, and root.
* How the array root represents a tree.
* What a Greedy Algorithm is.
  * Greedy Algorithm always make the choice that looks best at the moment.
* How a string of characters can encoded as a string of bits.
* What fixed length and variable length character codes are.
* What a Huffman Tree (HT) is.
* How an HT can to optimally encode a string.
* How an HT can decode an optimally encoded string.
* How Huffman’s Algorithm works.
* How Huffman’s Algorithm constructs an HT.
* Why Huffman’s Algorithm is a Greedy Algorithm.
