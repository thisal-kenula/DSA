# Binary Search
# Works for sorted arrays

def binary_search(arr, value):
    right = len(arr) - 1 # Last index
    left = 0 # First index
    
    while left <= right:
        mid = (left + right) // 2 # Get the mid value

        if arr[mid] == value:
            return mid
        
        if mid < value: # Value is larger
            left = mid 
        else: # Value is smaller
            right = mid

        # When using `left = mid` and `right = mid` without `+1`,
        # it would cause an infinity loop when value is last or
        # first.
        
    return -1

# USAGE

my_array  = [2, 3, 7, 7, 11, 15, 25, 28]
i = binary_search(my_array, 2)
print(i)