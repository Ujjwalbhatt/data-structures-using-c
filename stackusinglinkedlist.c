#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
int main()
{
    push();
    push();
    
    return 0;
}
void push(){
    int val;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Not able to push");
    }
    else{
        printf("Enter the value");
        scanf("%d",&val);
        if(head==NULL){
            ptr->data=val;
            ptr->next=NULL;
            head=ptr;
        }
         else   
        {  
            ptr->data = val;  
            ptr->next = head;  
            head=ptr;  
        }  
        printf("Item pushed");  
    }
}