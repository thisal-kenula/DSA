#include <iostream>

using namespace std;

template <size_t N>
int binarySearch(int (&arr)[N], int value);

int main() {
    int myArray[] = {2, 3, 7, 7, 11, 15, 25};
    
    int i = binarySearch(myArray, 25);
    cout << i << endl;

    return 0;
}

template <size_t N>
int binarySearch(int (&arr)[N], int value) {
    int left = 0; // Least index
    int right = N - 1; // Max index
    int mid; // Index of the mid element

    while (left <= right) {
        mid = (left + right) / 2;
        int midValue = arr[mid];

        if (midValue == value) {
            return mid;
        }
        else if (midValue < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return - 1; // Value not found
}