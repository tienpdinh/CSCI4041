from __future__ import print_function

class PriorityQueue:

    def __init__(self, lst, length):
        self.__queue = lst
        self.__length = length
        self.__heap_size = len(lst)

        if self.__length < self.__heap_size:
            raise Exception('Length cannot be less than heap size')

        for _ in range(0, self.__length - self.__heap_size):
            self.__queue.append(0)

        self._build_max_heap()

    def enqueue(self, key):
        if self.is_full():
            raise Exception('Queue is full')
        else:
            self._max_heap_insert(key)

    def dequeue(self):
        if self.is_empty():
            raise Exception('Deque is not supported for an empty queue')
        else:
            p = self.heap_max()
            self._heap_extract_max()
            return p

    def heap_max(self):
        return self._get(1)

    def _heap_increase_key(self, i, key):
        if key <= self._get(i):
            return
        self._set(i, key)
        j = i
        while j > 0 and self._get(self._parent(j)) > self._get(j):
            self._swap(j, self._parent(j))
            j = self._parent(j)   

    def is_full(self):
        return self.__heap_size == self.__length

    def is_empty(self):
        return self.__heap_size == 0

    def _heap_extract_max(self):
        self._set(1, self._get(self.__heap_size))
        self.__heap_size -= 1
        self._max_heapify(1)

    def _max_heap_insert(self, key):
        self.__heap_size += 1
        self._set(self.__heap_size, key - 1)
        self._heap_increase_key(self.__heap_size, key)

    def _build_max_heap(self):
        for i in range(self.__heap_size, 0, -1):
            self._max_heapify(i)

    def _max_heapify(self, i):
        largest = i
        l = self._left_child(i)
        r = self._right_child(i)
        if l <= self.__heap_size and self._get(l) > self._get(i):
            largest = l
        if r <= self.__heap_size and self._get(r) > self._get(largest):
            largest = r
        if largest != i:
            self._swap(i, largest)
            self._max_heapify(largest)

    def _left_child(self, i):
        return 2 * i

    def _right_child(self, i):
        return 2 * i + 1

    def _parent(self, i):
        return i // 2

    def _get(self, i):
        return self.__queue[i - 1]

    def _set(self, i, key):
        self.__queue[i - 1] = key

    def _swap(self, i, j):
        tmp = self._get(i)
        self._set(i, self._get(j))
        self._set(j, tmp)

    def __str__(self):
        return str(self.__queue)
