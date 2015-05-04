#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int* numbers, const int& low, const int& high) {
    int first_high = low;
    int pivot = high;
    for (int i = low ; i < high; i++) {
        if (numbers[i] < numbers[pivot]) {
            swap(numbers[i], numbers[first_high]);
            first_high++;
        }
    }
    swap(numbers[pivot], numbers[first_high]);
    pivot = first_high;
    return pivot;
}

int selection(int* numbers, int low, int high, int k) {
    int pivot = 0;
    int rank_pivot = 0;
    while (true) {
        pivot = partition(numbers, low, high);
        rank_pivot = pivot - low + 1;
        if (k > rank_pivot) {
            low = pivot + 1;
            k = k - rank_pivot;
        } else if (k < rank_pivot) {
            high = pivot - 1;
        } else {
            return numbers[pivot];
        }
    }
}

int main() {
    int numbers[] = {3, 1, 2, 1, 4};
    int low = 0;
    int high = 4;
    int k = 5;
    cout << selection(numbers, low, high, k) << endl;
}