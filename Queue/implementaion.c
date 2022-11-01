#include <stdio.h>
void enQueue(int);
void deQueue();
void display();
int items[5], front = -1, rear = -1;

int main()
{
    // deQueue is not possible on empty queue
    deQueue();

    // enQueue 5 elements
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    // 6th element can't be added to because the queue is full
    enQueue(6);
    display();

    // deQueue removss element entered first i.e. 1
    deQueue;

    // Now we have 4 elements
    display(4);

    return 0;
}
void enQueue(int value)
{
    if (rear == 5 - 1)
    {
        printf("\n Queue is FULL!!");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}
void deQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty!!");
    }
    else
    {
        printf("\nDeleted : %d", items[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Funtion to print the queue
void display()
{
    if (rear = -1)
    {
        printf("\nQueue is Empty!!");
    }
    else {
        int i;
        printf("\nQueue elements are:\n");
        for ( i = 0; i <= rear; i++)
        {
            printf("%d  ",items[i]);
        }
    }
        printf("\n");
}