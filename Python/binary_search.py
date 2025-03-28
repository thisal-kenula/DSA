# Binary Search
# Works for sorted arrays

def binary_search(arr, value):
    upper_bound = len(arr)
    lower_bound = - 1
    current_index = (upper_bound // 2)

    while lower_bound < upper_bound:
        current_value = arr[current_index]

        if current_value == value:
            return current_index
        
        elif current_value < value:
            lower_bound = current_index

        else:
            upper_bound = current_index

        current_index = lower_bound + (upper_bound - lower_bound) // 2

    return -1

# USAGE

my_array  = [2, 3, 7, 7, 11, 15, 25, 28]
i = binary_search(my_array,28)
print(i)