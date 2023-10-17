#include <iostream>
using namespace std;

/*
theory : complete binary tree

for any node :
left child : 2*i+1;
right child  : 2*i+2;
parent[child] = i/2;

-------insertion------
add value in the last index
take the value into its correct positon
index > 1 bcz index 1 is root node or top position

-------deletion----------
put last node element on root node
decrease the size
propogate the root node in correct pos

------Heapify-Algorithm --------
conversion of arr to heap is called

*/

class Heap
{
	int arr[100];
	int size;

public:
	Heap(int n)
	{
		size = 0;
	}

	void insert(int val)
	{
		size++;
		int index = size;
		arr[index] = val;
		while (index > 1)
		{
			int parent = index / 2;
			if (arr[parent] < arr[index])
			{
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else
			{
				return;
			}
		}
	}

	void DeleteFromHeap(int val)
	{
		if (size == 0)
			return;
		arr[1] = arr[size];
		size--;
		int i = 1;
		while (i < size)
		{
			int leftIndex = 2 * i;
			int rightIndex = 2 * i + 1;

			if (leftIndex <= size && arr[i] < arr[leftIndex])
			{
				swap(arr[i], arr[leftIndex]);
				i = leftIndex;
			}
			else if (rightIndex <= size && arr[i] < arr[rightIndex])
			{
				swap(arr[i], arr[rightIndex]);
				i = rightIndex;
			}
			else
			{
				return;
			}
		}
	}

	void printHeap()
	{
		for (int i = 1; i <= size; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

void HeapiFy(int arr[], int n, int i)
{
	int largest = i;
	int leftIndex = 2 * i;
	int rightIndex = 2 * i + 1;

	if (leftIndex <= n && arr[largest] < arr[leftIndex])
	{
		largest = leftIndex;
	}
	if (rightIndex <= n && arr[largest] < arr[rightIndex])
	{
		largest = rightIndex;
	}

	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		HeapiFy(arr, n, largest);
	}
}

void HeapSort(int arr[], int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		HeapiFy(arr, n, i);
	}

	int size = n;
	while (size > 1)
	{
		swap(arr[1], arr[size]);
		size--;
		HeapiFy(arr, size, 1);
	}
}

int main()
{
	Heap hp(5);
	hp.insert(50);
	hp.insert(55);
	hp.insert(53);
	hp.insert(52);
	hp.insert(54);
	hp.printHeap();

	int arr[] = {0, 50, 55, 53, 52, 54}; // Since you are using 1-based indexing, add a 0 at the beginning
	int n = sizeof(arr) / sizeof(arr[0]) - 1; // Decrease the size by 1
	HeapSort(arr, n);

	cout << "Sorted Array: ";
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
