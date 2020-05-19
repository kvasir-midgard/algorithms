// A naive C/C++ based recursive implementation of LIS problem
// http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
#include<stdio.h>
#include<stdlib.h>

// Recursive implementation for calculating the LIS
int getLis(int arr[], int n, int *maxgetLis_length)
{
    // Base case
    if (n == 1)
        return 1;

    int currentgetLis_length = 1;
    for (int i=0; i<n-1; i++)
    {
        // Recursively calculate the length of the LIS
        // ending at arr[i]
        int subproblemgetLis_length = getLis(arr, i, maxgetLis_length);

        // Check if appending arr[n-1] to the LIS
        // ending at arr[i] gives us an LIS ending at
        // arr[n-1] which is longer than the previously
        // calculated LIS ending at arr[n-1]
        if (arr[i] < arr[n-1] &&
            currentgetLis_length < (1+subproblemgetLis_length))
            currentgetLis_length = 1+subproblemgetLis_length;
    }

    // Check if currently calculated LIS ending at
    // arr[n-1] is longer than the previously calculated
    // LIS and update maxgetLis_length accordingly
    if (*maxgetLis_length < currentgetLis_length)
        *maxgetLis_length = currentgetLis_length;

    return currentgetLis_length;
}

// The wrapper function for getLis()
int lis(int arr[], int n)
{
    int maxgetLis_length = 1; // stores the final LIS

    // maxgetLis_length is passed as a reference below
    // so that it can maintain its value
    // between the recursive calls
    getLis( arr, n, &maxgetLis_length );

    return maxgetLis_length;
}

// Driver program to test the functions above
int main()
{
    int arr[] = {67, 25, 29, 84, 22, 11, 80, 8, 53, 76, 7, 80, 30, 6, 68};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", lis( arr, n ));
    return 0;
}
