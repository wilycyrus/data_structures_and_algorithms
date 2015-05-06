#include <iostream>

using namespace std;

int binary_search(int* array, int key, int low, int high)
{
	if (low > high)
		return -1;
	else
	{
		int middle = (int)(low + high)/2;
		if (array[middle] == key)
			return middle;
		else
		{
			if (array[middle] > key)
				return binary_search(array, key, low, middle - 1);
			else
				return binary_search(array, key, middle + 1, high);
		}
	}
}

int main(int argc, char** argv)
{
	int array[] = {1, 2, 3, 4};
	cout << binary_search(array, 2, 0, 4) << endl;
}