#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <ctime>
using namespace std;

void swap(vector<int> &a, int i,int j);
void BubbleSort(vector<int>& a);
void InsertionSort(vector<int> &a);
void MergeSort(vector<int> &a, int start, int end);
void Merge(vector<int> &a, int s, int e, int s1, int e1);
void QuickSort(vector<int> &a, int start, int end);
void dopeQuickSort(vector<int> &a, int start, int end);

int main(void)
{
	srand(time(NULL));
	vector<int> v;
	for(int i = 0; i < 8; i++)
		v.push_back(rand() % 10);

	for(int i = 0; i < 8; i++)
		cout << v[i] << " ";
	cout << endl;

	// // SelectionSort(v);
	// // BubbleSort(v);
	// // InsertionSort(v);
	// // MergeSort(v, 0, v.size());
	QuickSort(v, 0, v.size());

	for(int i = 0; i < 8; i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}

void QuickSort(vector<int> &A, int l, int r)
{
	if(r-l < 2) return;
	int randomise = (rand() % (r-l)) + l;
	swap(A, l, randomise);
	int yellow = l, pivot = l;
	for(int green = l; green < r; green++)
	{
		if(A[green] <= A[pivot])
		{
			swap(A, yellow, green);
			yellow++;
		}
	}
	// cout << yellow << endl;
	swap(A, pivot, yellow-1);
	QuickSort(A, 0, yellow-1);
	QuickSort(A, yellow, r);
}

void swap(vector<int> &a, int i,int j)
{
	int tmp = a[j];
	a[j] = a[i];
	a[i] = tmp;
}

void BubbleSort(vector<int>& a)
{
	int tmp;
	for(int i = 0; i < a.size(); i++)
		for(int j = 1; j < a.size(); j++)
			if(a[j] < a[j-1])
				swap(a, j, j-1);	
}

void SelectionSort(vector<int> &a)
{
	int minimum;
	for(int i = 0; i < a.size(); i++)
	{
		minimum = i;
		for(int j = i+1; j < a.size(); j++)
			if(a[j] < a[minimum])
				minimum = j;
		swap(a, i, minimum);
	}
}

void InsertionSort(vector<int> &a)
{
	for(int i = 1; i < a.size()-1; i++)
	{
		int current = i;
		while(a[current] < a[current-1] and current != 0)
			{
				swap(a, current, current-1);
				current--;
			}
	}		
}

void MergeSort(vector<int> &a, int start, int end)
{
	if(end - start < 2 or end <= start) return;
	if(end - start == 2)
		if(a[start] > a[end-1])
			swap(a, start, end-1);

	MergeSort(a, 0, (start+end)/2);	
	MergeSort(a, (start+end)/2, end);	
	Merge(a, 0, (start+end)/2, (start+end)/2, end);
}

void Merge(vector<int> &a, int s, int e, int s1, int e1)
{
	int k = s, j = s1, count = 0;
	vector<int> v;
	while(k < e or j < e1)
	{
		if((a[k] <= a[j] or j >= e1) and k < e)
		{
			v.push_back(a[k]);
			k++;
		}	
		else if((a[j] < a[k] or k >= e) and j < e1)
		{
			v.push_back(a[j]);
			j++;
		}
		count++;
	}
	for(int i = s, count = 0; i < e1 && count < v.size(); i++, count++)
		a[i] = v[count];
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void dopeQuickSort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  dopeQuickSort(a, l, m - 1);
  dopeQuickSort(a, m + 1, r);
}