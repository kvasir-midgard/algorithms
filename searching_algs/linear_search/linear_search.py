def linearSearch(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1

if __name__ == '__main__':
    arr = [1, 2, 3, 4, 5, 6, 7]
    key = 5

    test1 = linearSearch(arr, key)
    test2 = linearSearch(arr, 0)

    if test1 == 4:
        print("Element found test1 \t\tpassed")
    else:
        print("Element not found test1 \t\tfailed")

    if test2 == -1:
        print("Element not found test2 \tpassed")
    else:
        print("test2 \t\tfailed")
