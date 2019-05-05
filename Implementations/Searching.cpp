#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <ctime>
using namespace std;

bool LinearSearch(vector<int> a, int val);
bool BinarySearch(vector<int> a, int val, int start, int end);
bool BinarySearchIterative(vector<int> a, int val, int start, int end);

int main(void)
{
	srand(time(NULL));
	// int tmp[] = {1,7,7,6,1,3,6,9};
	vector<int> v;
	for(int i = 0; i < 8; i++)
		v.push_back(rand() % 10);
	sort(v.begin(), v.end());
	for(int i = 0; i < 8; i++)
		cout << v[i] << " ";
	cout << endl;

	int ind = rand() % v.size();
	if(rand() % 2 == 0)
		cout << "It is inside: " << ind << " " << BinarySearchIterative(v, v[ind],0 , v.size()) << endl;
	else 
	{
		int ran = rand();
		cout << "Not inside: " << BinarySearchIterative(v, ran,0 , v.size()) << " " << ran << endl;
	}
	return 0;
}

bool LinearSearch(vector<int> a, int val)
{
	for(int i = 0; i < a.size(); i++)
		if(a[i] == val)
			return true;
	return false;
}

// Recursive Implementation
bool BinarySearch(vector<int> a, int val, int start, int end)
{
	if(end - start < 1) return false;
	if(end - start == 1) return a[start] == val;
	if(a[(start+end)/2] == val) return true;
	if(val < a[(start+end)/2]) return BinarySearch(a, val, start, (start+end)/2);
	if(val > a[(start+end)/2]) return BinarySearch(a, val, (start+end)/2, end);
}

// Iterative Implementation
bool BinarySearchIterative(vector<int> a, int val, int start, int end)
{
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(a[mid] == val) return true;
		else if(val < a[mid])
			end = mid-1;
		else if(a[mid] < val)
			start = mid+1;		
	}
	return false;
}