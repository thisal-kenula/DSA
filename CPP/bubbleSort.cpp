// Probably can be optimized more
#include <iostream>

using namespace std;

template <size_t N>
void bubbleSort(int (&arr)[N]);

int main() {
    // Numbers to be sorted
    int nums[] = {33, 45, 40, 25, 17, 24};
    bubbleSort(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    return 0;
}

template <size_t N>
void bubbleSort(int (&arr)[N]) {
    for (int i = 0; i < N - 1; ++i) { // `i` for iteration
        int k = N - i - 1; // How many numbers should be compared
        for (int n = 0; n < k; ++n) { // `n` for index
            if (arr[n] > arr[n + 1]) {
                swap(arr[n], arr[n+1]);
            }
        }
    }
}

