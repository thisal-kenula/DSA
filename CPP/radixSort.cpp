// Radix Sort: for non-negaitve numbers

// This probably can be optimized by not using `vector`
// Optimized algorithm with explanation: https://grok.com/share/bGVnYWN5_c4991334-35e8-45f9-afd8-87111bc4f2ee

#include <iostream>
#include <vector>

using namespace std;

template <size_t N>
void radixSort(int (&arr)[N]);

template<size_t N>
int findMax(int (&arr)[N]);

int main() {
    int myArray[] = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(myArray);
    for (int num : myArray) {
        cout << num << " ";
    }

    return 0;
}

template <size_t N>
void radixSort(int (&arr)[N]) {
    int e = 1;
    int max_n = findMax(arr);

    for (int e = 1; max_n / e > 0; e*=10) {
        // 10 buckets for each digit
        vector<vector<int>> buckets(10);

        for (int num : arr) {
            buckets.at((num/e)%10).push_back(num);
        }

        // Sort the array
        int index = 0;
        for (int bucket = 0; bucket < 10; ++bucket) {
            for (int num : buckets.at(bucket)) {
                // `index++` increments the index after the value is assigned
                arr[index++] = num;
            }
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
