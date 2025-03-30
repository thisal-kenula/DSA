# Tested with Python 3.13.2

def bubble_sort(arr: list):
    n = len(arr)
    # Traverse through all array elements - 1 
    # (last element is automatically sorted)
    for i in range(n - 1):
        # Traverse the unsorted part of the array
        for j in range(n - i - 1):
            # Swap
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

myArray = [170, 45, 75, 90, 802, 24, 2, 66]
bubble_sort(myArray)
print(myArray)

