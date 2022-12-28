/*
Name- Ujjwal Bhatt
Roll no - 60
Student Id- 21011456
Section-K

Q5.Write a C program to implement time sharing environment (using circular linked list) for N processes, where CPU allocates time slots of 10ns for given N processes, then print which process will be completed in how much time.
*/

// SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insert(struct node *head, int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    p->next = head;
    return head;
}
int process(struct node *head)
{
    int time = 0;
    if (head == NULL)
    {
        return time;
    }
    struct node *temp = head;
    while (1)
    {
        if ((temp == head) && (temp->next == head) && (temp->data) <= 10)
        {
            free(temp);
            time = time + 10;
            return time;
        }
        else if ((temp->data) > 10)
        {
            int num = temp->data;
            num = num - 10;
            temp->data = num;
            time = time + 10;
            temp = temp->next;
        }
        else if ((temp->data) <= 10)
        {
            struct node *temp1 = head;
            while (temp1->next != temp)
            {
                temp1 = temp1->next;
            }
            if (temp == head)
            {
                temp1->next = temp->next;
                head = head->next;
                temp = head;
            }
            else
            {
                temp1->next = temp->next;
                struct node *p = temp;
                temp = temp->next;
                free(p);
            }
            time = time + 10;
        }
    }
    return time;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty!");
        return;
    }
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    return;
}
int main()
{
    struct node *head = NULL;
    printf("Enter the number of processes : ");
    int n;
    scanf("%d", &n);
    int i = 1;
    while (i <= n)
    {
        printf("process %d = ", i);
        int val;
        scanf("%d", &val);
        head = insert(head, val);
        i++;
    }
    printf("Processes are : ");
    display(head);
    printf("time taken to complete all processes(time slot = 10ms) = %dms", process(head));
    return 0;
}
