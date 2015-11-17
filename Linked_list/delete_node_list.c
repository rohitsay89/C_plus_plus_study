/*
  This code is written for deleting an element in a linked List 
  at the nth position of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head;

void Print();
void Delete_nth(int );
void Insert_end(int );

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
	temp1->data = data;
	temp1->next = NULL;
	temp->next = temp1;
}

void Delete_nth(int n){						/* function to delete an element in the list */
	int j=0;
	struct Node *temp;
	temp = head;
	if(n==1){						/* if node 1 is to be deleted then */
		head = temp->next;				/* store the link of the next node to head */
		free(temp);					/* Free the 1st node */
		return;						/* return to the main function */
	}
	for(j=1;j<n-1;j++){					/* if not first element then traverse through the list */
		temp = temp->next;
	}
	struct Node *temp1;					/* Create a temproroy variable */
	temp1 = temp->next;					/* store the link for n node to new variable */
	temp->next = temp1->next;				/* store the link for node n+1 to n node */
	free(temp1);						/* delete the nth node */
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
	int data = 0, i=0,n=0;
	printf("Program to delete a node from position 'n' in a linked list \n");
	printf("Enter data to make a linked list \n");

	for(i=0;i<10;i++){
		printf("Enter the number \n");
		scanf("%d", &data);
		Insert_end(data);
	}
	Print();
	for(i=0;i<3;i++){
		printf("Enter the element to delete \n");
		scanf("%d", &n);
		Delete_nth(n);
	}
	Print();
}