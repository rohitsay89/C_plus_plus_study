/*
  This code is written for making a doulbly linked list
  to insert node at begining InsertAtHead function is used
  to insert node at end InserAtTail is function used
  Print function prints the list in forward and
  ReversePrint, prints the list in reverse direction.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node *head;						/* Global head variable */

struct Node* GetNewNode(int x){					/* Seperate function to create a node from  */
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;					/* by using malloc the node is created in Heap section of memory */
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;						/* returns the address of new node */
}

void InsertAtHead(int x){					/* Function to insert node at begining */
	struct Node *temp = GetNewNode(x);
	if(head == NULL){					/* if list is empty store temp address in head pointer */
		head = temp;
		return;						/* return to main function */
	}
	head->prev = temp;					/* Make the backward link */
	temp->next = head;					/* make the forward link */
	head = temp;						/* save the new node address in head */
}

void InsertAtTail(int data){					/* Function to add node at end of list */
	struct Node *temp = head;
	if(temp == NULL){					
		temp = GetNewNode(data);			/* store data in the new node */
		head = temp;					/* if list is empty store temp address in head pointer */
		return;
	}
	while(temp->next != NULL){				/* traverse the list till end */
		temp = temp->next;				
	}
	struct Node *temp1 = GetNewNode(data);			/* after reaching end store the address of new node */
	temp->next = temp1;					/* adjust the links */
	temp1->prev = temp;
}

void Print(){
	struct Node *temp = head;
	printf("Printing Forward: \n");
	if(temp==NULL){
		return;
	}
	while(temp!=NULL){
		printf("%d \n", temp->data);
		temp = temp->next;
	}
}

void ReversePrint(){
	struct Node *temp = head;
	printf("\nPrinting reverse: \n");
	if(temp == NULL){
		return;
	}
	while(temp->next!=NULL){
		temp = temp->next;
	}

	while(temp->prev!=NULL){
		printf("%d \n", temp->data);
		temp = temp->prev;
	}
}

void main(){
	head = NULL;
	int data = 0, i=0;
	printf("Program for a doubly linked list \n");
	for(i=0;i<10;i++){
		printf("Enter the data : \n");
		scanf("%d", &data);
		InsertAtTail(data);
	}
	Print();
	ReversePrint();
}