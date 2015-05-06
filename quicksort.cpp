#include <iostream>
#include <algorithm>

using namespace std;

int partition(int* array, int low, int high)
{
	int pivot = high;
	int first_high = low;
	for (int i = low; i < high; ++i)
	{
		if (array[i] < array[pivot])
		{
			swap(array[i], array[first_high]);
			first_high++;
		}
	}
	swap(array[pivot], array[first_high]);
	pivot = first_high;
	return pivot;
}

void quicksort(int* array, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

int main(int argc, char** argv)
{
	int array[] = {3, 1, 5, 4, 2};
	quicksort(array, 0, 4);
	for (int i = 0; i < 5; ++i)
		cout << array[i] << ' ';
	return 0;
}