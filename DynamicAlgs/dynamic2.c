/*
dynamic2.c
--------------------------------------------------------------------------------
Dynamic Algorithm to find the longest common subsequence

We can recursively work back from the last index of each array. If the last
characters match then we can chek the previous characters of both arrays. If not
then check the previous character of whichever array position is larger.
*/

#include <bits/stdc++.h>

// compares two ints and returns the larger one
int compare(int a, int b) { return (a > b) ? a : b; }

// finds the longest common subsequence of two arrays
int lcs(char *A, char *B, int m, int n) {
  // check if either is empty
  if (m == 0 || n == 0) {
    return 0;
  }
  // check if last characters match
  if (A[m - 1] == B[n - 1]) {
    // recurse and decrement bot array positions
    return lcs(A, B, m - 1, n - 1) + 1;
  }
  // if last characters dont match
  else {
    // recurse picking the larger array position
    return compare(lcs(A, B, (m - 1), n), lcs(A, B, m, (n - 1)));
  }
}

// tester
int main() {
  char A[] = "YBPDRMBZQB";
  char B[] = "UJEWEQDAZC";
  int m = strlen(A);
  int n = strlen(B);
  printf("Length of the longest common subsequence is %d\n", lcs(A, B, m, n));
  return 0;
}
