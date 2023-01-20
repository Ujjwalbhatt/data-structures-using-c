// Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>

struct node { // node structure
  int vertex; // vertex number
  struct node* next; // pointer to next node in list
};
struct node* createNode(int); // create a node

struct Graph { // graph structure
  int numVertices;  // number of vertices
  struct node** adjLists; // adjacency lists
}; 

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node)); // allocate memory for node
  newNode->vertex = v; // set the vertex to v
  newNode->next = NULL; // set the next pointer to NULL
  return newNode; // return the node
}

// Create a graph
struct Graph* createAGraph(int vertices) { // vertices is the number of vertices
  struct Graph* graph = malloc(sizeof(struct Graph));// allocate memory for graph
  graph->numVertices = vertices; // number of vertices

  graph->adjLists = malloc(vertices * sizeof(struct node*));// allocate memory for adjacency lists

  int i;
  for (i = 0; i < vertices; i++) // initialize adjacency lists to NULL
  graph->adjLists[i] = NULL; // set all the head pointers to NULL

  return graph; // return the graph
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) { // s is the source vertex and d is the destination vertex
  // Add edge from s to d   
  struct node* newNode = createNode(d); // create a new node for destination vertex
  newNode->next = graph->adjLists[s]; // point the new node to the current head
  graph->adjLists[s] = newNode;  // point the head to the new node

  // Add edge from d to s
  newNode = createNode(s); // create a new node for source vertex 
  newNode->next = graph->adjLists[d]; // point the new node to the curre nt head
  graph->adjLists[d] = newNode; // point the head to the new node
}

// Print the graph
void printGraph(struct Graph* graph) { 
  int v; // vertex
  for (v = 0; v < graph->numVertices; v++) { // for each vertex
    struct node* temp = graph->adjLists[v]; // get the head of the list
    printf("\n Vertex %d\n: ", v); // print the vertex
    while (temp) { // traverse the list
      printf("%d -> ", temp->vertex); // print the vertex 
      temp = temp->next; // go to the next node
    } 
    printf("\n"); 
  }
}

int main() { 
  struct Graph* graph = createAGraph(3); // create a graph with 4 vsertices
  addEdge(graph, 0, 1); // add edges
  addEdge(graph, 0, 2); // add edges
  addEdge(graph, 0, 3); // add edges
  addEdge(graph, 0, 4); // add edges

  printGraph(graph); // print the graph



  return 0;
}

//in the form of diagram

// 0
// | \
// |  \
// |   \
// 1----2
//  \
//   \
//    \
//     3
     
// Output
// Vertex 0
// 3 -> 2 -> 1 ->
// Vertex 1
// 2 -> 0 ->
// Vertex 2
// 1 -> 0 ->
// Vertex 3
// 0 ->
 
 //dry run in form of table:

// 0 1 2 3 // vertex
// 0 0 1 1 // 0
// 1 1 0 0 // 1
// 2 1 0 0 // 2



