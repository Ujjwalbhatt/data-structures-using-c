//to delete the duplicate node in linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node** head, int x){
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=*head;
    *head=temp;
}
void print(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void deleteduplicate(struct node *head){
    struct node *p,*q,*temp;
    p=head;
    while(p!=NULL && p->next!=NULL){
        q=p;
        while(q->next!=NULL){
            if(p->data==q->next->data){
                temp=q->next;
                q->next=q->next->next;
                free(temp);
            }
            else{
                q=q->next;
                printf("%d \n");
            }
        }
        p=p->next;
    }
}


int main () {
    struct node *head=NULL;
    
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,4);
    insert(&head,6);
    deleteduplicate(head);
    print(head);
    
    
    
    

    return 0;
}