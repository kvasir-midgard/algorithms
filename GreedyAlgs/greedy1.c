/*
greedy1.c
--------------------------------------------------------------------------------
Takes in an array of (x,y) tuples representing the begin and end times for an
event and outputs the the maximum number of events that can be completed. It
sorts events by their end times and selects the event with the earliest end
time then finds the next event with a start time greater or equal to the
previously selected event. The optimal selection is printed out to terminal in
tupal form (x,y)
*/
#include <bits/stdc++.h>
using namespace std;

// define an event with a begin and end time
struct Event {
  int begin, end;
};

// compares the end times of two events as to sort them
bool EventCompare(Event x, Event y) { return (x.end < y.end); }

// prints out optimal selection of events that do not overlap
void printEvents(Event ray[], int n) {
  int idx = 0;

  sort(ray, ray + n, EventCompare);

  printf("List of selected events: \n");
  printf("(%d, %d)", ray[idx].begin, ray[idx].end);

  for (int jdx = 1; jdx < n; jdx++) {
    if (ray[jdx].begin >= ray[idx].end) {
      printf("(%d, %d)", ray[jdx].begin, ray[jdx].end);
      idx = jdx;
    }
  }
  printf("\n");
}

// tester
int main() {
  Event ray[] = {{4, 8}, {1, 3}, {3, 5}, {7, 10}, {6, 7}, {8, 9}, {0, 1}};
  int n = sizeof(ray) / sizeof(ray[0]);
  printEvents(ray, n);
  return 0;
}
