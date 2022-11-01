using System;

class binarySearch {
    static int search(int[] arr, int l, int r, int key) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[mid] > key) {
                return search(arr, l, mid - 1, key);
            }
            return search(arr, mid + 1, r, key);
        }
        return -1;
    }

    public static void Main() {
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        int key = 5;

        int test1 = search(arr, 0, arr.Length, key);
        int test2 = search(arr, 0, arr.Length, 0);

        if(test1 == 4) {
            Console.WriteLine("Element found test 1 \t\t passed");
        } else {
            Console.WriteLine("Element not found test 1 \t\t failed");
        }

        if(test2 == -1) {
            Console.WriteLine("Element not found test 2 \t passed");
        } else {
            Console.WriteLine("Element not found test 2 \t failed");
        }
    }
}