// Counting Sort for non-negative numbers

#include <iostream>
#include <vector>
// vector is required for creating buckets.
// because the size of the array is not known at compile time.

using namespace std;

template<size_t N>
int findMax(int (&arr)[N]);

template<size_t N>
void countingSort(int (&arr)[N]);


int main() {
    int myArray[] = {4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3};
    countingSort(myArray);

    for (int num : myArray) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

template<size_t N>
void countingSort(int (&arr)[N]) {
    // Create bucket for each number (including 0)
    const int length = findMax(arr) + 1;
    vector<int> buckets(length, 0);

    // Count the number of each element in the array
    for (int i : arr) {
        buckets[i]++;
    }

    // Sort the array
    int index = 0;
    for (int bucket = 0; bucket < length; ++bucket) {
        for (int n = 0; n < buckets[bucket]; ++n) {
            // `index++` increments the index after the value is assigned
            arr[index++] = bucket;
        }
    }

}

template<size_t N>
int findMax(int (&arr)[N]) {
    // Returns maximum number of the given array
    int maxNum = arr[0];

    for (int i : arr) {
        if (i > maxNum) {
            maxNum = i;
        }
    }

    return maxNum;
}