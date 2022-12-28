#include<stdio.h>
#include<stdlib.h>
#define SIZE 40

struct queue{
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int numVertices;
    struct node** adjLists;
    int * visited;
};

//BFS algoirthm
void bfs(struct Graph* graph, int startVertex){
    struct queue* q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);
        struct node* temp = graph->adjLists[currentVertex];
while (temp)
{
    int adjVertex = temp->vertex;

    if(graph->visited[adjVertex] == 0){
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
    }
    temp = temp->next;
}
}
}


