//write a programmme to print the circular linekd list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

void print(struct Node* head)
{
  struct Node *ptr = head;
  while (ptr->next != head)
  {
    ptr = ptr->next;
  } 
  printf("%d ",ptr->data);
  ptr=ptr->next;
    while (ptr->next!=head)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

    
}
int main()
{
  struct Node* head = NULL;
  struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

  head->data = 1;
  second->data=123;
    third->data=7;
    fourth->data=9;
  head->next = second;
  second->next = third;
    third->next=fourth;
    fourth->next=head;


  print(head);
  return 0;
}
