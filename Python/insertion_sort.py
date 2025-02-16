'''
Insertion Sort

Move each value to the left until it finds the correct position.
'''

def insertion_sort(arr: list):
    # Start from the second element
    # Because the first element has no left side to compare
    for i in range(1, len(arr)):
        current_val = arr[i]

        for j in range(i-1, -1, -1):
            # `i-1` to start from the left element of `i`
            # first `-1` to go to 0 index (because -1 is exclusive)

            if arr[j] > current_val:
                # Move elements in left side to the right until we find the
                # correct position for the current value
                arr[j+1] = arr[j]
            else:
                # When we find correct position, insert the current value
                # `j+1` because the arr[j] is smaller than `current_val`
                arr[j+1] = current_val
                break
        else:
            # If the current value is the smallest value in the array
            arr[0] = current_val


# USAGE
my_array = [64, 34, 25, 12, 22, 11, 90, 5]
insertion_sort(my_array)
print(my_array)