#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#define INF (1 << 31)
using namespace std;
const int MAX = 100000;
int heap_arr[MAX], heapSize = 0;

struct PriorityQueue
{
	int left(int i) { return 2 * i; }
	int right(int i) { return (2 * i) + 1;}
	int parent(int i) { return (i / 2); }

	void ShiftDown(int i)
	{
		int maxIndex = i, l = left(i), r = right(i);
		if(l <= heapSize and heap_arr[l] < heap_arr[maxIndex])
			maxIndex = l;
		if(r <= heapSize and heap_arr[r] < heap_arr[maxIndex])
			maxIndex = r;
		if(maxIndex != i)
		{
			swap(heap_arr[maxIndex], heap_arr[i]);
			ShiftDown(maxIndex);
		}
	}
	void ShiftUp(int i)
	{	
		while(i > 1 and heap_arr[i] < heap_arr[parent(i)])
		{
			swap(heap_arr[i], heap_arr[parent(i)]);
			i = parent(i);
		}
	}
	void Heapify(int N)
	{
		for(int i = N; i >= 1; i--)
			ShiftDown(i);
	}
	void Insert(int i)
	{
		heapSize++;
		heap_arr[heapSize] = i;
		ShiftUp(heapSize); 
	}
	void Remove(int i)
	{
		heap_arr[i] = INF;
		ShiftUp(i);
		pop();
	}	
	void ChangePriority(int i, int change)
	{
		Remove(i); Insert(change);
	}
	int top(void)
	{
		return heap_arr[1];
	}
	void pop(void)
	{
		swap(heap_arr[1], heap_arr[heapSize]);
		heapSize--; ShiftDown(1);
	}
};

int main(void)
{

	return 0;
}