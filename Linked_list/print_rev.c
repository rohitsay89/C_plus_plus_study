/*
  This code is written for printing a linked list in reverse or forward
  without actually changing the links
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void Reverse_Print(struct Node *p){
	if(p==NULL){
		return;
	}
	Reverse_Print(p->next);				/* Reverse print */
	printf("%d \n", p->data);
	
}

void Print(struct Node *p){
	if(p==NULL){
		return;
	}
	printf("%d \n", p->data);
	Print(p->next);					/* Forward print */
}

struct Node* Insert(struct Node *head, int data){	/* function to fill the list by inserting data at end */
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}
	else{
		struct Node *temp1 = head;
		while(temp1->next != NULL){
			temp1=temp1->next;
		}
		temp1->next = temp;
	}
	return head;
}

void main(){
	struct Node *head = NULL;
	head = Insert(head, 2);				/* fill the linked list by inserting at end */
	head = Insert(head, 4);				
	head = Insert(head, 6);
	head = Insert(head, 8);
	head = Insert(head, 726);

	Print(head);					/* Print elements in forward direction */
	Reverse_Print(head);				/* print elements in reverse direction */
	
}