# Tested with Python 3.13.2

def quick_sort(arr: list, start: int, end: int):
    if start >= end - 1:
        return

    pivot = arr[end-1]
    i = start - 1 # last index of value that is <= pivot value
    for j in range(start, end):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    quick_sort(arr, start, i)
    quick_sort(arr, i+1, end)

my_arr = [3, 4, 8, 10, 1, 2, 4]
quick_sort(my_arr, 0, len(my_arr))
print(my_arr)