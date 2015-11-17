/*
  This code is written for inserting and element in a linked List 
  at the nth position of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head;

void Insert_nth(int data, int n){
	int j=0;
	struct Node *temp;
	temp = head;
	if(temp == NULL){							/* Check if list is empty */
		temp = (struct Node*)malloc(sizeof(struct Node));		/* If emty the create the first node */
		temp->data = data;						/* Add data and point the head to this node */
		temp->next = NULL;
		head = temp;
		return;								/* Return back to the main function */
	}
	for(j=1;j<n-1;j++){							/* traverse the list till the insert location */
		temp = temp->next;
	}
	struct Node *temp1;							/* After reaching that point insert a node */
	temp1 = (struct Node*)malloc(sizeof(struct Node));			/* Allocate memory to it */
	temp1->data = data;							/* add data to new node */
	temp1->next = temp->next;						/* join the link of next node by coping pointer from previous node */
	temp->next = temp1;							/* Point the previous node to the new node */
}

void Insert_end(int data){
	struct Node *temp;
	temp = head;
	
	if(temp == NULL){
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data;
		temp->next = NULL;
		head = temp;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	struct Node *temp1;
	temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp->next = temp1;
	temp1->next = NULL;
	temp1->data = data;
}

void Print(){
	struct Node *temp;
	temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		printf("%d \n", temp->next);
		temp = temp->next;
	}
}

void main(){
	head = NULL;
	printf("Program to insert a node at nth position in the list \n");
	int data = 0, i = 0, n = 0;
	
	for(i=0;i<10;i++){							/* First create a linked list */
		printf("Enter the data \n");					/* Enter data at the end */
		scanf("%d", &data);
		Insert_end(data);
	}
	Print();								/* Print the linked list */
	for(i=0;i<2;i++){
		printf("Enter the data \n");
		scanf("%d", &data);						/* Enter the data */
		printf("Enter the location to be inserted in linked list \n");
		scanf("%d", &n);						/* Enter the position to insert for data */
		Insert_nth(data, n);						/* call the Insert_nth function and pass data and position as parameters */
	}
	Print();
}
