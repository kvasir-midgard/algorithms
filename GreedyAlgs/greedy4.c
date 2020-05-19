
#include <stdio.h>
#include <limits.h>

#define V 5

int minVals(int vals[], bool mst[])
{

   int min = INT_MAX;
   int minIdx;

   for (int idx = 0; idx < V; idx++){
     if (vals[idx] < min && mst[idx] == false){
         min = vals[idx], minIdx = idx;
     }
   }

   return minIdx;
}

int printer(int n, int parent[], int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int idx = 1; idx < V; idx++){
      printf("%d - %d    %d \n", parent[idx], idx, graph[idx][parent[idx]]);
   }
}

void prims(int graph[V][V])
{
     int parent[V];
     int vals[V];
     bool mst[V];


     for (int idx = 0; idx < V; idx++){
        vals[idx] = INT_MAX, mst[idx] = false;
    }


     vals[0] = 0;
     parent[0] = -1;


     for (int idx = 0; idx < V-1; idx++){


        int u = minVals(vals, mst);


        mst[u] = true;




        for (int v = 0; v < V; v++){
          if (graph[u][v] && mst[v] == false && graph[u][v] <  vals[v])
             parent[v]  = u, vals[v] = graph[u][v];
        }
     }


     printer(V, parent, graph);
}


int main()
{

   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };


    prims(graph);

    return 0;
}
