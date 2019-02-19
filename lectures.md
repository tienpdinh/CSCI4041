# Feb 19, 2019

## Hashing
**Given a key, want to be able to get the corresponding value as fast as possible**

### Hash Table
**No restrictions on what the keys are**
Array can maps integer keys over a small range to arbitrary values in O(1). Assume 0 <= key < M. If we have a table `T`:
```
DIRECT-ADDRESS-SEARCH(T,k):
    return T[k]

DIRECT-ADDRESS-INSERT(T,x):
    T[x.key] = x

DIRECT-ADDRESS-DELETE(T,x):
    T[x.key] = NIL
```
*Note: This is not working well because there are more possible keys than there are array indexes.*

Instead of using a key `k` directly as an index, use 0 <= h(k) < M. h(k) is called the **hash function**.

#### Collisions
##### Resolving Collisions by chaining
 * Where two keys give the same indexes. We can avoid collisions by making each hash bucket is the root node of a linked list.

 ```
CHAINED-HASH-INSERT(T, x):
    insert x into the list at T[h(x.key)]

CHAINED-HASH-SEARCH(T, x):
    search for an element in T[h(k)]
    with key k

CHAINED-HASH-DELETE(T, x):
    delete x from the list at T[h(x.key)]
 ```

*But how fast can we do this?*

##### Possibility
Expected value:
E[x] = sum xPr(X=x)
Lotteries:
 * Losttery that pays $10^6
 * Each ticket costs $1
 * Pr[win] = 1/10^6
 * P = payoff
E[p]= sum xPr{X=p} = 10^6 + 0(1-1/10^6) = $1 - Fair!

 * Lottery pays $10^3
 * Each ticket costs $1
 * Pr[win] = 1/10^6
E[p] = 10^3 / 10^6 + 0(1-1/10^6) => unfair!

### Uniform hashing
We have 0 <= h(k) < M
Pr{h(k) = j} = 1/M (Pick key at random, there is equal chance that it will end up somewhere in the table.)
We want to do this because we want to keep the bucket as short as possible.

### Clustering
Certain buckets are more likely to be ended up with than the rest. We want to avoid this, because this will cause a lot of collisions.