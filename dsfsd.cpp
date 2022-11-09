#include<stdio.h>
#include<stdlib.h>
struct node{

	int data;
	struct node* next;

};

void insertatend(struct node **head, int x){
	 	struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=NULL;
		if(*head==NULL){
			
		*head=temp;
		}	
		else{
			struct node *ptr=*head;
			while(ptr->next!=NULL){
					ptr=ptr->next;
			}
			ptr->next=temp;
		
		}
		
		
}

void display(struct node *head){
	if(head==NULL){
		printf("list is empty");
	}
	else{

	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	}
}
int main(){
	struct node*head=NULL;
	insertatend(&head,45);
	insertatend(&head,35);
	insertatend(&head,75);
	insertatend(&head,95);
	display(head);
	return 0;

}