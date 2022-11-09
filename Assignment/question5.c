// insert the node at the end of the double linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

// insert the node at the end of the double linked list
void insert(struct Node *head, int d)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *q = head;
  ptr->data=d;
  while (q->next != NULL)
  {
    q = q->next;
  }
  q->next = ptr;
  ptr->prev=q;
  ptr->next = NULL;
}
// print the double linked list
void print(struct Node* head)
{
  struct Node *ptr = head;

  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}
int main()
{
  struct Node* head = NULL;
  struct Node* second = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  head->data = 1;
  second->data=123;
  head->next = second;
  head->prev = NULL;
  second->prev=head;
  second->next=NULL;


    insert(head,7);
   
  
    print(head);
    

  return 0;
}
