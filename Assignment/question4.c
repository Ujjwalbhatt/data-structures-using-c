#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void lessernode(struct node *head, int x)
{
    struct node *start = head;
    while (start != NULL && start->next != NULL)

    {
        if (start->data < x)
        {
            printf("%d ", start->data);
        }
        start = start->next;
    }
    printf("%d",start->data);
}
void display(struct node *head){
    struct node *start = head;
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}
int main()
{

    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));
    struct node *fifth = malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = NULL;
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("The nodes with data less than %d are: ", x);
    lessernode(head, x);
    
    printf("The linked list is: ");
    display(head);

    return 0;
}