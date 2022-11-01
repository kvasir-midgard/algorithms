#include <stdio.h>

int binarySearch(int arr[], int l, int r, int key) {
    if(r>=l){
      int m = l + (r-l)/2;
      if(arr[m] == key){
        return m;
      }
      if(arr[m]>key){
        return binarySearch(arr, l, m-1, key);
      }
      return binarySearch(arr, m+1, r, key);
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]) - 1;
    int key = 5;

    int test1 = binarySearch(arr, 0, len, key);
    int test2 = binarySearch(arr, 0, len, 0);

    if(test1 == 4) {
        printf("Element found test 1 \t\t passed \n");
    } else {
        printf("Element not found test 1 \t\t failed \n");
    }

    if(test2 == -1) {
        printf("Element not found test 2 \t passed \n");
    } else {
        printf("Element not found test 2 \t failed \n");
    }
}