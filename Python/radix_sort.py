def radix_sort(arr: list):
    '''
    Sorts the given list of non-negaitve numbers in place using Radix Sort algorithm
    arr: list of non-negative numbers
    return: None
    '''
    e = 1
    max_n = max(arr)

    # Loop until all the digits of the maximum number is considered
    while max_n // e > 0:
        digi_grp = [[] for i in range(10)]  # Create 10 empty lists for each digit group

        # Add the numbers to the respective digit group
        for num in arr:
            digi_grp[(num//e)%10].append(num)

        # Copy the sorted elements back to the original array
        index = 0
        for bucket in range(10):
            for num in digi_grp[bucket]:
                arr[index] = num
                index += 1

        e *= 10 # Move to the next digit

# USAGE

myArray = [170, 45, 75, 90, 802, 24, 2, 66]

radix_sort(myArray)
print(myArray)