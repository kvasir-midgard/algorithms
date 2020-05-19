/*
greedy2.c
--------------------------------------------------------------------------------
Kruskal’s Minimum Spanning Tree Algorithm

Given a connected and undirected graph this algorithm will search a minimum
spanning tree of the graph which is a tree on the edges of the original graph
of least weight.

- sort edges in increasing order of their weight
- check if smallest edge forms a cycle in the spanning tree
  if no cycle then include the edge, else discard it.
- repeat the last step until graph is a tree aka has (V-1) edges
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for weighted edges in graph made of source, endination, and weight
struct Edge {
  int start, end, weight;
};

// Structure for connected, undirected and weighted graph
struct Graph {
  int V, E;           // number of vertex and edges
  struct Edge* edge;  // array list representation of graph, edge = (u, v)
};

// Structure which represent a subset of the graph for union-search
struct subset {
  int rank;
  int parent;
};

// Build graph with V vertices and E edges
struct Graph* buildGraph(int V, int E) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
  return graph;
}

// searchs set for a given element using path compression
int search(struct subset subs[], int elem) {
  // search root and use path compression to make it parent of elem
  if (subs[elem].parent != elem) {
    subs[elem].parent = search(subs, subs[elem].parent);
  }
  return subs[elem].parent;
}

// Unions two sets a and b via union by rank
void Union(struct subset subs[], int a, int b) {
  // get roots for each element
  int rootA = search(subs, a);
  int rootB = search(subs, b);

  // join smaller tree to the root of larger tree
  if (subs[rootA].rank < subs[rootB].rank) {
    subs[rootA].parent = rootB;
  } else if (subs[rootA].rank > subs[rootB].rank) {
    subs[rootB].parent = rootA;
  }
  // break the tie if ranks are the same
  else {
    subs[rootB].parent = rootA;
    subs[rootA].rank++;
  }
}

// Compare edges based on weight
int edgeCompare(const void* edge1, const void* edge2) {
  struct Edge* x = (struct Edge*)edge1;
  struct Edge* y = (struct Edge*)edge2;
  return x->weight > y->weight;
}

// Kruskal's algorithm for constructing MST of a connected undirected graph
void Kruskals(struct Graph* graph) {
  int V = graph->V;      // number of vertex in graph
  int idx = 0;           // indexing variable for sorted edges
  int jdx = 0;           // indexing variable for final final
  struct Edge final[V];  // stores final MST

  // sort edges based on their weight from smallest to largest
  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), edgeCompare);

  // allocate memory for vertex subsets
  struct subset* subs = (struct subset*)malloc(V * sizeof(struct subset));

  // build a vertex subset for a given element
  for (int v = 0; v < V; ++v) {
    subs[v].parent = v;
    subs[v].rank = 0;
  }

  // while MST in incomplete continue to build
  while (idx < (V - 1)) {
    // check if added edge creates a cycle, if not then add to MST
    struct Edge next_edge = graph->edge[jdx++];

    int set1 = search(subs, next_edge.start);
    int set2 = search(subs, next_edge.end);

    // if sets are disjoint then union them
    if (set1 != set2) {
      final[idx++] = next_edge;
      Union(subs, set1, set2);
    }
  }

  // output MST to terminal
  printf("List of edges in MST: \n");
  for (jdx = 0; jdx < idx; ++jdx) {
    printf("(%d, %d), weight: %d\n", final[jdx].start, final[jdx].end,
           final[jdx].weight);
  }
  free(subs);
  return;
}

// tester
int main() {
  int V = 6;
  int E = 8;

  struct Graph* graph = buildGraph(V, E);

  graph->edge[0].start = 0;
  graph->edge[0].end = 3;
  graph->edge[0].weight = 5;

  graph->edge[1].start = 0;
  graph->edge[1].end = 4;
  graph->edge[1].weight = 7;

  graph->edge[2].start = 0;
  graph->edge[2].end = 5;
  graph->edge[2].weight = 13;

  graph->edge[3].start = 1;
  graph->edge[3].end = 3;
  graph->edge[3].weight = 13;

  graph->edge[4].start = 1;
  graph->edge[4].end = 4;
  graph->edge[4].weight = 5;

  graph->edge[5].start = 1;
  graph->edge[5].end = 5;
  graph->edge[5].weight = 7;

  graph->edge[6].start = 2;
  graph->edge[6].end = 3;
  graph->edge[6].weight = 2;

  graph->edge[7].start = 2;
  graph->edge[7].end = 5;
  graph->edge[7].weight = 3;

  Kruskals(graph);

  // clean up allocated memory
  free(graph->edge);
  free(graph);
  return 0;
}
