#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node
{
    int vertex;
    int weight;
    struct node *next;
};
struct node *createNode(int v, int w)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}
struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    // Add edge from src to dest
    struct node *newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d ", v);
        while (temp)
        {
            printf("-> %d (%d)", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}
struct node *getEdgeWithMinimumWeight(struct Graph *graph)
{
    struct node *temp = NULL;
    int min = 9999;
    int i;
    for (i = 0; i < graph->numVertices; i++)
    {
        struct node *adjList = graph->adjLists[i];
        struct node *temp2 = adjList;
        while (temp2)
        {
            if (temp2->weight < min && graph->visited[temp2->vertex] == 0)
            {
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
    for (i = 0; i < graph->numVertices; i++)
    {
        struct node *temp = getEdgeWithMinimumWeight(graph);
        if (graph->visited[temp->vertex] == 0)
        {
            printf("\nEdge %d - %d with weight %d is selected  for MST \t", i, temp->vertex, temp->weight);
            cost += temp->weight;
            graph->visited[temp->vertex] = 1;
        }
    }
    printf("\nCost of the graph is %d", cost);
    printf("\n*********************************************"); 
    printf("\nProgram Prepared & Executed by: Ujjwal Bhatt, CSE(K), Class Roll no: 60" ); 

}
int main()
{
    struct Graph *graph = createGraph(6);
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
    printGraph(graph);
    kruskal(graph);
    return 0;
}

