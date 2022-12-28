/*
Q3.Write a C program to create a linked list P, then write a ‘C’ function named split to create two linked lists Q & R from P So that Q contains all elements in odd positions of P and R contains the remaining elements. Finally print both linked lists i.e. Q and R.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
void printList(struct Node * head) {
    struct Node * ptr = head;
    while (ptr) {
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("NULL\n");
}
void insert(struct Node ** head, int data) {
    struct Node * newNode = (struct Node * ) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = * head;
    * head = newNode;
}
void moveNode(struct Node ** destRef, struct Node ** sourceRef) {
    if ( * sourceRef == NULL) {
        return;
    }
    struct Node * newNode = * sourceRef;
    * sourceRef = ( * sourceRef) -> next;
    newNode -> next = * destRef;
    * destRef = newNode;
}
void Split(struct Node * source, struct Node ** PRef, struct Node ** QRef) {
    struct Node * P = NULL;
    struct Node * Q = NULL;
    struct Node * current = source;
    while (current != NULL) {
        moveNode( & P, & current);
        if (current != NULL) {
            moveNode( & Q, & current);
        }
    }
    * PRef = P;
    * QRef = Q;
}
int main(void) {
    int n;
    printf("Enter no of elements :");
    scanf("%d", & n);
    struct Node * P = NULL;
    for (int i = n - 1; i >= 0; i--) {
        int data;
        printf("Enter element:");
        scanf("%d", & data);
        insert( & P, data);
    }
    struct Node * Q = NULL, * R = NULL;
    Split(P, & Q, & R);
    printf("First List (Q): ");
    printList(Q);
    printf("Second List (R): ");
    printList(R);
    return 0;
}
