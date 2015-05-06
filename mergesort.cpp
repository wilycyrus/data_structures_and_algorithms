#include <iostream>
#include <queue>

using namespace std;

void merge(int* array, int low, int middle, int high)
{
	queue<int> low_que;
	queue<int> high_que;

	for (int i = low; i <= middle; ++i)
		low_que.push(array[i]);
	for (int i = middle + 1; i <= high; ++i)
		high_que.push(array[i]);

	int i = low;
	while (!(low_que.empty() or high_que.empty()))
	{
		if (low_que.front() < high_que.front())
		{
			array[i++] = low_que.front();
			low_que.pop();
		}
		else
		{
			array[i++] = high_que.front();
			high_que.pop();
		}
	}
	while (!low_que.empty())
	{
		array[i++] = low_que.front();
		low_que.pop();
	}
	while (!high_que.empty())
	{
		array[i++] = high_que.front();
		high_que.pop();
	}
}

void mergesort(int* array, int low, int high)
{
	if (low < high)
	{
		int middle = (int)(low + high)/2;
		mergesort(array, low, middle);
		mergesort(array, middle + 1, high);
		merge(array, low, middle, high);
	}
}

int main(int argc, char** argv)
{
	int array[] = {3, 1, 5, 4, 2};
	mergesort(array, 0, 4);
	for (int i = 0; i < 5; ++i)
		cout << array[i] << ' ';
	return 0;
}