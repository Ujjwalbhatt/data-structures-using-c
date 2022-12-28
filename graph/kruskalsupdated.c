#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// This structure represents a node in the adjacency list.
struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

// This structure represents an adjacency list.
struct AdjList
{
    struct Node *head; // Pointer to head node of list
};

// This structure represents a graph, which is an array of adjacency lists.
// The size of the array will be V (number of vertices in the graph).
struct Graph
{
    int V;
    struct AdjList *array;
    int *visited; // for dfs only
};

// This function creates a graph with V vertices.
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = vertices;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList *)malloc(vertices * sizeof(struct AdjList));

    graph->visited = malloc(vertices * sizeof(int)); // for dfs only
    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < vertices; ++i)
    {
        graph->array[i].head = NULL;
        graph->visited[i] = 0; // for dfs only
    }
    return graph;
}

// This function adds an edge to an undirected graph.
void addEdge(struct Graph *graph, int s, int d,int w)
{
    struct Node *dest, *temp, *src;
    if (graph->array[s].head == NULL)
    {
        src = (struct Node *)malloc(sizeof(struct Node));
        src->vertex = s;
        src->next = NULL;
        src->weight = w;
        graph->array[s].head = src;
    }
    dest = (struct Node *)malloc(sizeof(struct Node));
    dest->vertex = d;
    dest->next = NULL;
    dest->weight=w;
    temp = graph->array[s].head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = dest;
}

// This function prints the adjacency list representation of graph
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        struct Node *temp = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp)
        {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct Node* getEdgeWithMinimumWeight(struct Graph* graph) {
  struct Node* temp = graph->array[0].head; // Initialize temp to first edge in graph
  int min = 1000000; // Initialize min to a large value
  for (int i = 0; i < graph->V; i++) {
    struct Node* adjList = graph->array[i].head;
    struct Node* temp2 = adjList;
    while (temp2) {
      if (temp2->weight < min && graph->visited[temp2->vertex] == 0) {
        min = temp2->weight;
        temp = temp2;
      }
      temp2 = temp2->next;
    }
  }
  return temp;
}


void kruskal(struct Graph *graph)
{
    int i;
    int cost = 0;
    for (int i = 0; i < graph->V; i++)
    {
        struct Node *temp = getEdgeWithMinimumWeight(graph);
        if (graph->visited[temp->vertex] == 0)
        {
            printf("\nEdge %d - %d with weight %d is selected for MST \t", i , temp->vertex, temp->weight);
            cost += temp->weight;
            graph->visited[temp->vertex]=1;
        }
    }
}

int main()
{
    // Create a graph with 5 vertices
    int V = 5;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 0, 4);
    addEdge(graph, 2, 0, 3);
    addEdge(graph, 2, 1, 1);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 2, 5, 6);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 2, 2);
    addEdge(graph, 3, 4, 7);
    addEdge(graph, 4, 2, 5);
    addEdge(graph, 4, 3, 7);
    addEdge(graph, 5, 2, 6);
    addEdge(graph, 5, 4, 8);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    kruskal(graph);

    return 0;
}
