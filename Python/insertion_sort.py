'''
Insertion Sort

Move each value to the left until it finds the correct position.
'''

def insertion_sort(arr: list):
    # Start from the second element
    # Because the first element has no left side to compare
    for i in range(1, len(arr)):
        current_val = arr[i]
        j = i - 1

        # Check all items to the left until we find a smaller value than
        # the current value(currentVal)
        while j >= 0 and arr[j] > current_val:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = current_val

# USAGE
my_array = [64, 34, 25, 12, 22, 11, 90, 5]
insertion_sort(my_array)
print(my_array)