#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void insertatbeg(struct Node **head, int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *head;
    *head = temp;

} 
int main () {
      struct Node *head = NULL;
    insertatbeg(&head, 1);
    insertatbeg(&head, 3);
    insertatbeg(&head, 31);
    insertatbeg(&head, 345);
    insertatbeg(&head, 65);
    insertatbeg(&head, 67);
    
    return 0;
}