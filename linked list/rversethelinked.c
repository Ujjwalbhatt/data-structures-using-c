#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createnode(int value){
    struct node* temp = (struct node*) malloc (sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
struct node* node(struct node *head,int value){
        struct node * temp  = createnode(value);
        if(head!=NULL){
            head->next = temp;
        }
        head = temp;
        return head;
}

void print(struct node* head){
    struct node* p =head;
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
struct node* reverse(struct node* head){
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = nextnode = head;
    while (nextnode!=NULL)
    {   
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
     head = prevnode;
        return head;
}
int main(){
    int n=0;
    int value;
    struct node *ptr1 = NULL;
    struct node *ptr2 = NULL;   
    ptr2 = ptr1 = node(ptr1,23);
    ptr1 = node(ptr1,23);
    ptr1 = node(ptr1,24);
    ptr1 = node(ptr1,25);
    ptr1 = node(ptr1,54);
    print(ptr2);
    ptr2 = reverse(ptr2);
    print(ptr2);
    

    return 0;
}