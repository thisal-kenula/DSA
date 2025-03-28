// Linear Search
// Works for integer arrays
// Returns the index of the first found element. -1 if not found

#include <iostream>

using namespace std;

template <size_t N>
int linearSearch(int (&arr)[N], int value);

int main(){
    int myArray[] = {2, 3, 7, 7, 11, 15, 25};
    int number = 7;
    int index = linearSearch(myArray, number);
    
    cout << "Index of " << number << " = " << index;
    return 0;
}

template <size_t N>
int linearSearch(int (&arr)[N], int value) {
    for (int i=0; i < N; ++i) {
        if (arr[i] == value) { // If the element is found
            return i; // Return the index of the element
        }
    }

    return -1; // Element not found
}