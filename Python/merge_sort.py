# Merge Sort (using recursion)
# Works for all integer and float values
# Returns a new sorted array, does not modify the original array

import dis

def merge_sort(arr: list):
    length = len(arr)

    # If the array has only one element
    if length <= 1:
        return arr

    # Split the array into two halves and sort each half
    sorted_left = merge_sort(arr[0:length//2])
    sorted_right = merge_sort(arr[length//2:length])

    # Sort and merge the two halves
    return merge(sorted_left, sorted_right)

# Sort and merge two halves
def merge(left: list, right: list):
    i = 0 # currently comparing index of the left array
    j = 0 # currently comparing index of the right array
    sorted = [] # Store the sorted array

    # While there are elements in both arrays:
    # compare the elements and add the smaller one to the sorted array
    while i < len(left) and j < len(right):
        if left[i] > right[j]:
            sorted.append(right[j])
            j += 1
        else:
            sorted.append(left[i])
            i += 1

    # Add the remaining elements to the sorted array
    sorted += left[i:] + right[j:]

    return sorted


# USAGE
unsortedArr = [3, 7, 6, -10, 15, 23.5, 55, -13]
sortedArr = merge_sort(unsortedArr)
print("Sorted array:", sortedArr)