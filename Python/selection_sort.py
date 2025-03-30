'''
Selection Sort

In each iteration, find the minimum element from the unsorted part
of the array and swap it with the first element of the unsorted part.  
Tested with Python 3.13.2
'''

def selection_sort(nums: list):
    n = len(nums) # Number of elements in the list

    # Traverse through all array elements - 1 
    # (Because the last element will be sorted automatically)
    for i in range(n - 1):
        min_indx = i # Mark the first element as the minimum

        # Find the minimum element in the unsorted part of the array
        # i + 1 because the first element is already marked as minimum
        for j in range(i + 1, n): 
            if nums[j] < nums[min_indx]:
                min_indx = j

        # Swap the found minimum element with the first element 
        # of the unsorted part
        nums[i], nums[min_indx] = nums[min_indx], nums[i]

# Usage
my_array = [64, 34, 25, 5, 22, 11, 90, 12]
selection_sort(my_array)
print(my_array)