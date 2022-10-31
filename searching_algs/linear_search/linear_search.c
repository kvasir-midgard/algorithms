#include <stdio.h>

int linearSearch(int arr[], int len, int key) {
    for (int i = 0; i < len; i++) {
        if(arr[i] == key) { return i; }
    } return -1;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int test1 = linearSearch(arr, len, key);
    int test2 = linearSearch(arr, len, 0);


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