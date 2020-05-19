/*
greedy5.c
--------------------------------------------------------------------------------
Dijkstra's single shortest path algorithm for adjacency matrix of a graph

*/

#include <stdio.h>
#include <limits.h>

// Structure for building an adjacency matrix of a graph
template <size_t V>
struct Graph {
  int data[V][V];  // holds data for adjacency matrix of a graph

  // some random data for the adjacency matrix of a graph
  int mRay[V][V] = {
      {0, 3, 1, 3, 3, 8, 0, 0, 3, 4, 0},  {1, 0, 2, 0, 0, 16, 5, 3, 0, 6, 1},
      {2, 3, 0, 0, 1, 1, 4, 1, 1, 0, 0},  {5, 3, 3, 0, 5, 0, 2, 2, 2, 2, 1},
      {1, 0, 0, 6, 0, 1, 2, 6, 10, 2, 4}, {0, 11, 3, 0, 1, 0, 8, 3, 1, 3, 3},
      {2, 4, 1, 7, 6, 7, 0, 6, 0, 8, 2},  {1, 2, 1, 3, 8, 4, 4, 0, 4, 3, 0},
      {0, 0, 0, 1, 4, 1, 3, 4, 0, 6, 4},  {0, 3, 0, 0, 0, 5, 2, 2, 6, 0, 4},
      {0, 1, 0, 0, 2, 1, 2, 0, 1, 2, 0}};

  // could edit this loop to read in data from file to build graph
  Graph() {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        data[i][j] = mRay[i][j];
      }
    }
  }
};

// prints minimum distance from source for all vertex
int printer(int dist[], int src, int V) {
  printf("Vertex   Distance from vertex %d\n", src);
  for (int i = 0; i < V; i++) {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

// Finds vertex closest to source not currently included in shortest path tree
int minDist(int dist[], bool isDone[], int V) {
  int min = INT_MAX;  // holds minimum distance from src to a given vertex
  int minIdx;         // holds index of min distance in dist array

  for (int v = 0; v < V; v++) {
    if (isDone[v] == false && dist[v] <= min) {
      min = dist[v];
      minIdx = v;
    }
  }

  return minIdx;
}

// Dijkstra's shortest path alg for adjacency matrix of a graph
template <size_t V>
void dijkstra(const Graph<V>& graph, int src) {
  int dist[V];     // holds distance of shortest path for all vertex
  bool isDone[V];  // holds if shortest path for vertex found or not

  // initalize distance values to inf and if vertex is done to false
  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX, isDone[i] = false;
  }

  dist[src] = 0;  // set distance from src to itself to zero

  // find shortest path for all vertex
  for (int i = 0; i < (V - 1); i++) {
    int u = minDist(dist, isDone, V);  // get min dist vertex not already done
    isDone[u] = true;

    // chnge vertex distance if not done, there is an edge from u to v and
    // path from src to v through u is shorter than current vertex dist
    for (int v = 0; v < V; v++) {
      if (!isDone[v] && graph.data[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph.data[u][v] < dist[v]) {
        dist[v] = dist[u] + graph.data[u][v];
      }
    }
  }

  printer(dist, src, V);
}

// tester
int main() {
  // if reading in from file V could be found here
  const int V = 11;
  Graph<V> graph;
  dijkstra(graph, 0);
  return 0;
}
