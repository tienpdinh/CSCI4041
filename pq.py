# Priority Queue
# Incomplete.
import numpy as np

class PQ:
	def __init__(self, init_size = 64):
		self.pqueue = [0] * init_size
		self.heapSize = 0
		self.size = init_size

	# helper functions.
	@staticmethod
	def left_child(index):
		return 2*index+1
	@staticmethod
	def right_child(index):
		return 2*index+2
	@staticmethod
	def parent(index):
		return (index+1)//2-1

	def swap(self, i, j):
		temp = self.pqueue[i]
		self.pqueue[i] = self.pqueue[j]
		self.pqueue[j] = temp
	
	def isFull(self):
		return self.heapSize >= self.size

	def insert(self, start, key):
		index = start
		self.pqueue[index] = key
		while index > 0 and key > self.pqueue[self.parent(index)]:
			self.swap(index, self.parent(index))		
			index = self.parent(index)
		self.heapSize += 1
	
	def enqueue(self, key):
		if self.isFull():
			self.pqueue += [0]*self.size
			self.size *= 2
		self.insert(self.heapSize, key)

	def printing(self, index, depth):
		if index>=self.heapSize:
			return
		space = " "*depth
		print(space+str(self.pqueue[index]))
		# print left subtree
		self.printing(self.left_child(index), depth+1)
		# print right subtree
		self.printing(self.right_child(index), depth+1)
		
	def print(self):
		self.printing(0,0)
