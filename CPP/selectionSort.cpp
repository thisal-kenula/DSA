// TODO: NOT DONE YET

#include <iostream>

using namespace std;

template <size_t N>
void selectionSort(int (&arr)[N]);

int main() {
    int nums[] = {33, 45, 40, 25, 17, 24};
    selectionSort(nums);

    for (int number : nums) {
        cout << number << " ";
    }
    return 0;
}

template <size_t N>
void selectionSort(int (&arr)[N]) {
    int min_id = 0; // index of the smallest value
    for (int i = 0; i < N - 1; ++i) {
        int min_value = arr[min_id];

        for (int j = i; j < N; ++j) {
            if (arr[j] < min_value) {
                min_id = j;
            }
        }
        swap(arr[i], arr[min_id]);
    }
}