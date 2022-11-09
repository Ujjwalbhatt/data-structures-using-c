//Assume that you have single link list with pointer p, at first node. write a programme to input a number and search it in the list. If it is found insert a new node after that node in the linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *p=NULL;
void insert(int x)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=x;
temp->next=p;
p=temp;
}
void display()
{
    
}

int main () {

    return 0;
}
