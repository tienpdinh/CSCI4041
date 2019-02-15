# Priority Queue

PQ is an ADT, that is a black box with `insert` and element with priority value. And `return` an element with min priority.

## Min Heap

**Is an efficient implementation of PQ**
 1. Correspondence with Array
 2. Heap structure, node <= children

### Associated functions:
 * Extract-Min, log n
 * Increase-Key, log n
 * Decrease-Key, log n
 * Insert-Key, log n
 * Build-a-heap, n

#### Extract-Min
Exchange with the end of the array. O(logn)

#### Increase-Key
If a key is increased, it will sink down to its appropriate position, O(logn)

#### Decrease-Key
Similar to `Increase-Key`

#### Insert-Key
Insert the element to the end of the array, then decide its position O(logn)

#### Build-a-heap
 * Visit nodes from the end of the array to the beginning of the array
 * When visiting a node, we need to make sure everything below that node is a correct heap
 * The number of operation is bounded by the number of edges, there are n-1 edges. Further observation, time complexity is the number of edges minus the last branch.

## Heap Sort
 1. Build a heap
 2. Recursively call the function `Extract-Min`, and swap it with the last element.
 3. Call heapify on the first element.