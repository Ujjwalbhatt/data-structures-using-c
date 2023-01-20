#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int r;
    int f;
    int *arr;
};

int isfull(struct queue* q){
    if((q->r+1)%q->size==q->f){
    return 1;
    }
    return 0;

}
int  isEmpty(struct queue* q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q, int value){
    if(isfull(q)){
        printf("queue is full");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
    }
}

void dequeue(struct queue* q){
    int a=0;
    if(isEmpty(q)){
        printf("queue is empty\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
        printf("Dequeuing element %d\n",a);
    }
    
    
}
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));

    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,11);
    enqueue(&q,12);
    enqueue(&q,13);
    ( dequeue(&q));
    ( dequeue(&q));
    ( dequeue(&q));
    ( dequeue(&q));
    ( dequeue(&q));
    ( dequeue(&q));
    enqueue(&q,13);
    ( dequeue(&q));

  
    return 0;
}