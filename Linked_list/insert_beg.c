/*
  This code is written for inserting and element in a linked List 
  at the begning of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{								/* create a structure */
	int data;							/* having data and next node pointer */
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

void Insert_beg(int data){						/* function to insert at begining */
	struct Node *temp;						/* Create a temprory struct pointer */
	temp = head;							/* store head value i.e. poin it to the first node */
	if(temp == NULL){						/* if head is NULL then create first node */
		temp = (struct Node*)malloc(sizeof(struct Node));	/* allocate memory to first node */
		temp->data = data;					/* store data in first node */
		temp->next = NULL;					/* poin it to NULL */
		head = temp;						/* point head to the first node */
		return;							/* exit from the function */
	}
	struct Node *temp1;						/* if head is not NULL then */
	temp1 = (struct Node*)malloc(sizeof(struct Node));		/* create a new node and allocate memory */
	temp1->next = temp;						/* link the new node with first node */
	temp1->data = data;						/* insert data to new node node */
	head = temp1;							/* make new node as first node of list pointing head to it */
}

void main(){								/* Main function start here */
	head = NULL;							/* give head as NULL value at starting of code */
	printf("Program to insert data at the begining of a linked list \n");
	int data = 0, i = 0;						/* define variables */
	for(i=0;i<10;i++){						/* run the for loop 10 times to insert data */
		printf("Enter the number \n");
		scanf("%d", &data);					/* Take data from user */
		Insert_beg(data);					/* insert it in the begining */
	}
	Print();							/* Print the whole list */
}

/*
  Output:
10 10363240
9 10363224
8 10363208
7 10363192
6 10363176
5 10363160
4 10363144
3 10363128
2 10365400
1 0

*/



