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
int main(){


    return 0;
}