def moveZerosToEnd(arr):
    zeroCount = 0
    n = len(arr)

    # Traverse the array. If arr[i] is non-zero, put the element at its proper place.
    for i in range(n):
        if arr[i] != 0:
            arr[zeroCount] = arr[i]
            zeroCount += 1

    # Now all non-zero elements have been shifted to front and 'count' is set as index of first 0. Make all elements 0 from count to end.
    while zeroCount < n:
        arr[zeroCount] = 0
        zeroCount += 1

    return arr

# Test the function
arr = [1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9]
print("Original Array: ", arr)
arr = moveZerosToEnd(arr)
print("Modified Array: ", arr)
