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
void searchlink(struct Node **head, int element){
    struct Node* p= *head;
    do
    {
        if(p->data==element){
            printf("Element found the linked list\n");
            p->next=p->next->next;
            return;
        }
        else{
            p=p->next;

        }
    }while ((p->next!=NULL));
}
void display(struct Node *head ){
    
    while(head!=NULL){
        printf("%d\n", head->data);
        head=head->next->next;
    }
    // printf("%d\n", head->data);
}
int main () {
    struct Node *head = NULL;
    insertatbeg(&head, 1);
    insertatbeg(&head, 3);
    insertatbeg(&head, 31);
    insertatbeg(&head, 345);
    insertatbeg(&head, 65);
    insertatbeg(&head, 67);
    display(head);
    searchlink(&head, 3);
      display(head);
    return 0;
}