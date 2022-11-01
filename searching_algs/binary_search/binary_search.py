def binarySearch(arr, l, r, x): 
    if r >= l:
        mid = l + (r - l) // 2 
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)
        else:
            return binarySearch(arr, mid + 1, r, x)
    else:
        return -1

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5, 6, 7]
    len = len(arr)-1
    key = 5

    test1 = binarySearch(arr, 0, len, key)
    test2 = binarySearch(arr, 0, len, 0)

    if test1 == 4:
        print("Element found test1 \t\tpassed")
    else:
        print("Element not found test1 \t\tfailed")

    if test2 == -1:
        print("Element not found test2 \tpassed")
    else:
        print("test2 \t\tfailed")
