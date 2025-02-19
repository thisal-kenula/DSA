#include <iostream>

using namespace std;

template<size_t N>
void insertionSort(int (&arr)[N]);

int main() {
    int myArray[] = {64, 34, 25, 12, 22, 11, 90, 5};
    insertionSort(myArray);

    for (int i : myArray) {
        cout << i << " ";
    }
    return 0;
}

template<size_t N>
void insertionSort(int (&arr)[N]) {
    for (int i=1; i < N; ++i) {
        int currentVal = arr[i];
        int j = i - 1; // Index of the item to the left of the current value

        // Check all items to the left until we find a smaller value than
        // the current value(currentVal)
        while (j >= 0 && arr[j] > currentVal) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = currentVal;
        /*
        Behind the scenes:
        1. Current value > all values to the left:
                0 1 2 3   4   (index)
                1 2 3 4 **5** (values) 5: current value
                4 > 5 : false
                --j -> j = 3
                arr[3 + 1] = 5

        2. Current value puts in the middle:
                0 1 2 3   4   (index)
                1 2 4 5 **3** (value)
                when j = 1: arr: 1 2 4 4 5
                2 > 3: false
                --j -> j = 0
                arr[0 + 1] = 3

        3. Current value < all values to the left:
                0 1 2 3   4   (index)
                5 4 3 2 **1** (value)
                when j = 0: arr: 5 5 4 3 2
                5 > 1: true
                --j -> j = -1
                arr[-1 + 1] = 1
        */
    }
}