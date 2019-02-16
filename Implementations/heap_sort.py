class HeapSort:

    def __init__(self, lst):
        self.lst = lst.copy()
        self.heap_size = len(self.lst)

    def sort(self, descending=False):
        if descending:
            self.__build_min_heap()
            for i in range(self.heap_size, 1, -1):
                self.__swap(1, i)
                self.heap_size -= 1
                self.__min_heapify(1)
        else:
            self.__build_max_heap()
            for i in range(self.heap_size, 1, -1):
                self.__swap(1, i)
                self.heap_size -= 1
                self.__max_heapify(1)
        return self.lst

    def __build_max_heap(self):
        for i in range(self.heap_size, 0, -1):
            self.__max_heapify(i)

    def __build_min_heap(self):
        for i in range(self.heap_size, 0, -1):
            self.__min_heapify(i)

    def __max_heapify(self, index):
        largest = index
        l = self.__left_child_index(index)
        r = self.__right_child_index(index)
        if l <= self.heap_size and self.__get(l) > self.__get(index):
            largest = l
        if r <= self.heap_size and self.__get(r) > self.__get(largest):
            largest = r
        if largest != index:
            self.__swap(index, largest)
            self.__max_heapify(largest)

    def __min_heapify(self, index):
        smallest = index
        l = self.__left_child_index(index)
        r = self.__right_child_index(index)
        if l <= self.heap_size and self.__get(l) < self.__get(index):
            smallest = l
        if r <= self.heap_size and self.__get(r) < self.__get(smallest):
            smallest = r
        if smallest != index:
            self.__swap(index, smallest)
            self.__min_heapify(smallest)

    def __swap(self, index, index2):
        tmp = self.__get(index)
        self.__set(index, self.__get(index2))
        self.__set(index2, tmp)

    def __get(self, index):
        return self.lst[index - 1]

    def __set(self, index, value):
        self.lst[index - 1] = value

    def __left_child_index(self, index):
        return 2 * index

    def __right_child_index(self, index):
        return 2 * index + 1
