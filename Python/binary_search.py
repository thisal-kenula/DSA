# Binary Search
# Works for sorted arrays
# Tested with Python 3.13.2

def binary_search(arr, value):
    right = len(arr) - 1 # Last index
    left = 0 # First index
    
    while left <= right:
        mid = (left + right) // 2 # Get the mid value

        if arr[mid] == value:
            return mid
        
        if arr[mid] < value: # Value is larger
            left = mid + 1
        else: # Value is smaller
            right = mid - 1

        # When using `left = mid` and `right = mid` without `+1` and `-1`,
        # it would cause an infinity loop when value is last or
        # first.
        
    return -1

# USAGE

my_array  = [2, 3, 7, 7, 11, 15, 25, 28]
i = binary_search(my_array, 15)
print(i)