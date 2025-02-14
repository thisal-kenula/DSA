def bubble_sort(arr: list):
    n = len(arr)
    for i in range(n - 1):
        for j in range(i, n - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                # CONTINUE HERE

myArray = [170, 45, 75, 90, 802, 24, 2, 66]
bubble_sort(myArray)
print(myArray)

