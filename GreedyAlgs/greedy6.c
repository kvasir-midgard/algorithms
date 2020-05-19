/*
greedy4.c
--------------------------------------------------------------------------------
Knapsack problem using a greedy alg that takes the ratio of the value to weight
to choose the optimal selection of items to pu in the knapsack.
*/

#include <bits/stdc++.h>
using namespace std;

// structure for objects to go into the knapsack with a weight and value
struct object {
  int val;
  int weight;
  object(int val, int weight) : val(val), weight(weight) {}
};

// compares values based on the value to weight ratio
bool compare(struct object x, struct object y) {
  double a = (double)x.val / x.weight;
  double b = (double)y.val / y.weight;
  return a > b;
}

// greedy alg to find optimal selection of objects that fit in the knapsack
double knapsack(struct object ray[], int canFit, int n) {
  int curr = 0;                   // current weight of the knapsack
  double result = 0.0;            // maximum value that fits in the knapsack
  sort(ray, (ray + n), compare);  // sort values based on value to weight ratio

  // prints weight, value, and ratio of objects in the knapsack
  for (int i = 0; i < n; i++) {
    cout << ray[i].weight << " \t " << ray[i].val << " \t "
         << ((double)ray[i].val / ray[i].weight) << endl;
  }

  // find optimal selection
  for (int i = 0; i < n; i++) {
    // put highest ratio item in bag if it fits
    if (curr + ray[i].weight <= canFit) {
      curr += ray[i].weight;
      result += ray[i].val;
    }
    // if it does not fit then add a part of it
    else {
      int remainder = canFit - curr;
      result += ray[i].val * ((double)remainder / ray[i].weight);
      break;
    }
  }
  return result;
}

// tester
int main() {
  object ray[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(ray) / sizeof(ray[0]);
  int canFit = 50;
  cout << "weight \t value \t ratio" << endl;
  cout << "Max value is = " << knapsack(ray, canFit, n) << endl;

  return 0;
}
