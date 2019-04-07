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
* Strategies for probing: linear probing, quadratic probing, double hashing.
* What a Binary Search Tree (BST) is (as discussed in lecture).
* How to add a key/value pair to a BST.
* How to find the value that corresponds to a key in a BST.
* How to delete a key/value pair from a BST.
* What a balanced BST is.
* What an unbalanced BST is.
* Run times of BST algorithms for add, find, delete.
* What memoization is.
* What top-down and bottom-up memoization is.
* How the Fibonacci example (from lecture) uses memoization.
* What Dynamic Programming (DP) is.
* How memoization is like DP.
* What an Optimal Binary Search Tree (OBST) is.
* What success nodes (k’s) and failure nodes (d’s) are.
* How probabilities of these nodes (p’s and q’s) work.
* What an expected value is.
* How to compute the expected value of search in an OBST.
* How to generate all possible OBST’s for a sorted list of keys.
* How Cormen’s algorithm OPTIMAL-BST works.
* How OPTIMAL-BST uses the arrays e, w, and root.
* How the array root represents a tree.
* What a Greedy Algorithm is.
* How a string of characters can encoded as a string of bits.
* What fixed length and variable length character codes are.
* What a Huffman Tree (HT) is.
* How an HT can to optimally encode a string.
* How an HT can decode an optimally encoded string.
* How Huffman’s Algorithm works.
* How Huffman’s Algorithm constructs an HT.
* Why Huffman’s Algorithm is a Greedy Algorithm.
