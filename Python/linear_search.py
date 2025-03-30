# Tested with Python 3.13.2

import dis

def linear_search(array, value):
    '''
    Return the index of given value in the givenn array.
    
    Parameters:
        array (list): A list of values.
        value (int): The value to search for.
        
    Returns:
        int: The index of the value in the array.
    '''
    for i, crnt_val in enumerate(array):
        if crnt_val == value:
            return i
    
    return -1

# EXAMPLE USAGE

arr = [3, 7, 2, 9, 5]
targetVal = 9

result = linear_search(arr, targetVal)

if result != -1:
    print("Value",targetVal,"found at index",result)
else:
    print("Value",targetVal,"not found")
    

dis.dis(linear_search)