//searching the node in linked list and delete the node in linked list
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
    while (p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
} 
void search(struct node *head, int x){
    struct node *p,*temp;
    int count=0;
    p=head;
    while(p!=NULL && p->next!=NULL){
         if(p->next->data==x)  {
            temp=p->next;
            p->next=p->next->next;
            free(temp);
            count=1;
            return;
         } 
         else{
            p=p->next;
         }
         
    }
    if(count==0){
        printf("Data not found");
    }
}
int main(){
    struct node *head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    search(head, 3);
    search(head, 3);
    print(head);
    return 0;

}