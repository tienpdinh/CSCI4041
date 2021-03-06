# Binary Tree Implementation
# We only deal with complete or nearly complete binary tree
#           10
#       9        7      <= This is an example of a nearly complete BT
#     3    5
#  0   0 1   1
# This is NOT a binary search tree

class BinaryTree:

    def __init__(self, tree):
        """
        Args:
        tree: List representation of Binary Tree
        """
        self.tree = tree
        self.heap_size = len(tree)

    def left_child(self, index):
        return 2 * (index + 1)

    def right_child(self, index):
        return 2 * (index + 1) + 1

    def parent(self, index):
        return (index + 1) // 2

    def max_heapify(self, index):
        largest = 0
        left_index = self.left_child(index)
        right_index = self.right_child(index)
        if left_index <= self.heap_size and self.tree[left_index] > self.tree[index]:
            largest = left_index
        else:
            largest = index
        if right_index <= self.heap_size and self.tree[right_index] > self.tree[largest]:
            largest = right_index
        if largest != index:
            self.swap(index, largest)
            self.max_heapify(largest)

    def swap(self, index, largest):
        tmp = self.tree[index]
        self.tree[index] = self.tree[largest]
        self.tree[largest] = tmp
