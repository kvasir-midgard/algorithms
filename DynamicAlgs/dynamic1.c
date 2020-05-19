/*
dynamic1.c
--------------------------------------------------------------------------------
Dynamic Algorithm to find longest increasing subsequence (liss)

This is a recursive problem such that for an array[0....n-1]
liss(idx) = max(liss(jdx)) + 1 s.t. 0 < jdx < idx and array[jdx] < array[idx]
if jdx does not exist then liss(idx) = 1
*/

#include <stdio.h>
#include <stdlib.h>

// find liss given array, number of elements, and a place to stor the answer
int liss(int ray[], int *maxLen, int n) {

  // base case
  if (n == 1) {
    return 1;
  }

  int currLen = 1; // base case length

  // Recursively find length of liss ending at each index
  for (int i = 0; i < (n - 1); i++) {
    int newLen = liss(ray, maxLen, i);

    // check for recusive conditions for new length are met
    if (currLen < (1 + newLen) && ray[i] < ray[n - 1]) {
      currLen = 1 + newLen;
    }
  }

  // update max length if current is larger
  if (*maxLen < currLen) {
    *maxLen = currLen;
  }

  return currLen;
}

// getter for recursive function
int getLiss(int ray[], int n) {
  int maxLen = 1;
  liss(ray, &maxLen, n);
  return maxLen;
}

int main() {
  int ray[] = {67, 25, 29, 84, 22, 11, 80, 8, 53, 76, 7, 80, 30, 6, 68};
  int n = sizeof(ray) / sizeof(ray[0]);
  printf("Length of longest increasing subsequence is %d\n", getLiss(ray, n));
  return 0;
}
