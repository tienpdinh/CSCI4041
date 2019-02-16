from heap_sort import HeapSort
import random
import unittest

class LearningCase(unittest.TestCase):
    def test_random_1(self):
        lst = random.sample(range(100), 50)
        lst_heap_sort = HeapSort(lst)
        lst.sort()
        self.assertEqual(lst, lst_heap_sort.sort())
    def test_random_2(self):
        lst = random.sample(range(100), 70)
        lst_heap_sort = HeapSort(lst)
        lst.sort(reverse=True)
        self.assertEqual(lst, lst_heap_sort.sort(descending=True))
    def test_random_3(self):
        lst = random.sample(range(200), 70)
        lst_heap_sort = HeapSort(lst)
        lst.sort()
        self.assertEqual(lst, lst_heap_sort.sort())
    def test_random_4(self):
        lst = random.sample(range(50), 20)
        lst_heap_sort = HeapSort(lst)
        lst.sort(reverse=True)
        self.assertEqual(lst, lst_heap_sort.sort(descending=True))


def main():
    unittest.main()

if __name__ == '__main__':
    main()