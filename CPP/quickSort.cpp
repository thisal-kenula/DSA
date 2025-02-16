// Quick Sort Algorithm

#include <iostream>

using namespace std;

template <size_t N>
void quickSort(int (&arr)[N], int start=0, int last=N-1);

int main() {
    int myArray[] = {64, 34, 25, 12, 22, 11, 90, 28};
    quickSort(myArray);

    for (int i : myArray) {
        cout << i << " ";
    }
    return 0;
}

template <size_t N>
void quickSort(int (&arr)[N], int start, int last) {
    // arr: array to be sorted
    // start: starting index of the array
    // last: last index of the array

    if (start >= last) {
        // start == last: The array has only one element
        // start > last: The array has no element
        return;
    }

    int lsi = start - 1; // last smaller index (index of the last element smaller than the pivot)
    int pivot = arr[last]; // value of pivot element

    for (int i = start; i <= last; ++i) {
        // Find the last smaller index
        if (arr[i] <= pivot) {
            ++lsi;
            
            // Swap if the current element is smaller than the pivot
            if (lsi != i) {
                swap(arr[lsi], arr[i]);
            }
        }
    }

    // Recursively sort the left and right subarrays
    quickSort(arr, start, lsi-1);
    quickSort(arr, lsi+1, last);
}