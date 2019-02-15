# Binary Tree Implementation
# We only deal with complete or nearly complete binary tree
# This is NOT a binary search tree
# Incomplete

class BinaryTree:

	def __init__(self, heap_size, tree):
		self.tree = tree
		self.heap_size = heap_size

	def left_child(self, index):
		return 2 * (index + 1)

	def right_child(self, index):
		return 2 * (index + 1) + 1

	def parent(self, index):
		return (index + 1) // 2

	def max_heapify(self, index):
		left_index = left_child(index)
		right_index = right_child(index)
		if left_index <= self.heap_size and self.tree[left_index] > self.tree[index]:
			pass
