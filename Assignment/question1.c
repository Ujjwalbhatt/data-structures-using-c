#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void insertatbeg(struct node **head, int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *head;
    *head = temp;
} 




int main () {
    struct Node *head = NULL;
    insertatbeg(&head, 1);
    
    return 0;
}