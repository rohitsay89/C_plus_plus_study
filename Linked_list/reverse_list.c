/*
  This code is written for reversing the linked List using iterative method
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{								/* create a structure */
	int data;								/* having data and next node pointer */
	struct Node *next;
};

struct Node *head;							/* create a head of the list as global variable */

void Print(){
	struct Node *temp;
	temp = head;
	while(temp!=NULL){
		printf("%d ", temp->data);
		printf("%d \n", temp->next);
		temp = temp->next;
	}
}

void Insert_end(int data){
	struct Node *temp;
	temp = head;
	if(temp==NULL){
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
	temp1->data = data;
	temp1->next = NULL;
	temp->next = temp1;
}

void reverse(){
	struct Node *prev, *current, *next;
	current = head;
	prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
}

void main(){								/* Main function start here */
	head = NULL;							/* give head as NULL value at starting of code */
	printf("Program to insert data at the end of a linked list \n");
	int data = 0, i = 0;					/* define variables */
	for(i=0;i<10;i++){						/* run the for loop 10 times to insert data */
		printf("Enter the number \n");
		scanf("%d", &data);					/* Take data from user */
		Insert_end(data);					/* insert it in the begining */
	}
	Print();								/* Print the whole list */
	reverse();								/* Call reverse function */
	Print();								/* print the reversed list */
}