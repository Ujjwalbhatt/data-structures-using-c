#include <stdio.h>
#include <stdlib.h>

// This structure represents a node in the adjacency list.
struct Node {
  int vertex;
  struct Node* next;
};

// This structure represents an adjacency list.
struct AdjList {
  struct Node* head;  // Pointer to head node of list
};

// This structure represents a graph, which is an array of adjacency lists.
// The size of the array will be V (number of vertices in the graph).
struct Graph {
  int V;
  struct AdjList* array;
  int *visited; //for dfs only
};

// This function creates a graph with V vertices.
struct Graph* createGraph(int vertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = vertices;

  // Create an array of adjacency lists.  Size of array will be V
  graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
  
  graph->visited = malloc(vertices * sizeof(int)); //for dfs only
  // Initialize each adjacency list as empty by making head as NULL
  for (int i = 0; i < vertices; ++i){

    graph->array[i].head = NULL;
        graph->visited[i] = 0;//for dfs only
  }

  return graph;
}

// This function adds an edge to an undirected graph.
void addEdge(struct Graph* graph, int s, int d) {
    struct Node *dest, *temp, *src;
    if(graph->array[s].head == NULL){
        src = (struct Node*)malloc(sizeof(struct Node));
        src->vertex = s;
        src->next = NULL;
        graph->array[s].head = src;
    }
    dest = (struct Node*)malloc(sizeof(struct Node));
    dest->vertex = d;
    dest->next = NULL;
    temp = graph->array[s].head;
    while(temp->next !=NULL){
      temp=temp->next;
    }
    temp->next = dest;
}

// This function prints the adjacency list representation of graph
void printGraph(struct Graph* graph) {
  for (int v = 0; v < graph->V; ++v) {
    struct Node* temp = graph->array[v].head;
    printf("\n Adjacency list of vertex %d\n head ", v);
    while (temp) {
      printf("-> %d", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}




// DFS traversal of the vertices reachable from v.
void DFS(struct Graph* graph, int vertex) {
  
  struct Node* adjList = graph->array[vertex].head;

  struct Node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while(temp != NULL) {
    int connectedVertex = temp->vertex;

    if(graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}
// Driver program to test above functions

int main() {
  // Create a graph with 5 vertices
  int V = 5;
  struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    DFS(graph, 2);



    return 0;
}
