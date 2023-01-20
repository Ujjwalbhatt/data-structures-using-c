#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};

struct node* createAnode(int value){
    struct node* p=(struct node*) malloc(sizeof(struct node));
    p->value = value;
    p->next = NULL;
    return p;
}

struct node* insert(struct node* head,int value){
      struct node* temp = createAnode(value);
      if(head!= NULL){
      temp->next = head;
      }

      head = temp;

      return head;
}
void print(struct node* head){
    while (head!=NULL)
    {
        printf("%d ", head->value);
        head= head->next;
    }
    printf("\n");
    
}
void sortlinked(struct node * head){
    struct node *current= head;
    struct node *index = NULL;
    int temp;
    while(current!=NULL){
        index = current->next;
        while (index!=NULL)
        {

            temp =current->value;
            if(current->value > index->value){
            current->value = index->value;
            index->value = temp;
            }
            index = index->next;
        }
        current= current->next;
    }
}

int main(){
    struct node *head = NULL;
    head=insert(head,12);
    head=insert(head,22);
    head=insert(head,132);
    head=insert(head,123);
    print(head);
    sortlinked(head);
    print(head);
    return 0;
}