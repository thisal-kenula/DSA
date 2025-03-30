'''
Counting Sort

Sorts by counting the number of time each value occurs.  
Fast when the range of possible values < number of values.  
Otherwise, the array created for counting will be larger than the array being sorted.  
Works for non-negative integers.

Tested with Python 3.13.2
'''

def counting_sort(arr: list):
    max_num = max(arr) # How many numbers are required
    buckets = [0] * (max_num+1) # Create a bucket for each number

    # Count the number of times each number appears
    for i in arr:
        buckets[i] += 1

    arr.clear() # Clear the original array

    # Add the numbers back to the array in order
    for i, num in enumerate(buckets):
        for _ in range(num):
            arr.append(i)

# USAGE
my_array = [4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3]
counting_sort(my_array)
print(my_array)