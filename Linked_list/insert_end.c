/*
  This code is written for inserting and element in a linked List 
  at the end of list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{								/* create a structure */
	int data;							/* having data and next node pointer */
	struct Node *next;
};

struct Node *head;							/* create a head of the list as global variable */

void Insert_end(int data){						/* function to insert at end */
	struct Node *temp;						/* create a temporary variable */
	temp = head;							/* store head value of list into it */
	
	if(temp == NULL){						/* if starting of the list i.e. head is NULL */
		temp = (struct Node*)malloc(sizeof(struct Node));	/* create a node */
		temp->data = data;
		temp->next = NULL;
		head = temp;						/* Store data in it, point it to NULL and store */
		return;							/* its address to head as it is the first node. */
	}
	
	while(temp->next != NULL){					/* if its not te first node then  */
		temp = temp->next;					/* traverse throught he list */
	}
	struct Node *temp1;						/* after reacing the end */
	temp1 = (struct Node*)malloc(sizeof(struct Node));		/* create a node and add to the end */
	temp->next = temp1;						/* connect the link of new node with the list */
	temp1->next = NULL;						/* point new node to NULL */
	temp1->data = data;						/* add data to the new node */
}

void Print(){								/* function for printing data of list */
	struct Node *temp;						/* create a temp variable */
	temp = head;							/* point it to the list by storing head to it */
	while(temp != NULL){						/* traverse throught list till the last node */
		printf("%d ", temp->data);				/* print data */
		printf("%d \n", temp->next);				/* print address of next node */
		temp = temp->next;					/* point to the next node */
	}
}

int main(){								/* main function */
	head = NULL;							/* point head to NULL */
	printf("Code to insert data at the end of the list \n");
	int data=0;							/* declare variables */
	int i=0;
	for(i=0;i<10;i++){						/* loop for inserting 10 nodes at the end of list */
		printf("Enter the data \n");
		scanf("%d", &data);					/* Enter data */
		Insert_end(data);					/* pass data to insert function */
	}
	Print();							/* call print function to print data on console */
	return 0;
}

/*
after printf("%d \n", temp);

1 3549656
2 3547384
3 3547400
4 3547416
5 3547432
6 3547448
7 3547464
8 3547480
9 3547496
10 3547512

*/

/*
after printf("%d \n", temp->next);

1 4989176
2 4989192
3 4989208
4 4989224
5 4989240
6 4989256
7 4989272
8 4989288
9 4989304
10 0

*/
