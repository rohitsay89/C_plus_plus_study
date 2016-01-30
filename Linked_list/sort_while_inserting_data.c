/* sorting while inserting in a linked list */
/* Made from scratch */

#include <stdio.h>
#include <stdlib.h>

struct Node{					/* node structure decleration */
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void Insert_head(int n){			/* function for inserting a node in the begining */
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = head;
	head = temp;
	//printf("inserted data at end is: %d \n", temp->data);
}

void Insert_end(int n){				/* subroutine for inserting a node at the end */
	struct Node *temp;
	temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = n;
	temp1->next = NULL;
	temp->next = temp1;
	//printf("inserted data at end is: %d \n", temp1->data);
}

void Insert(int n){				/* Insert main function */
	struct Node *temp, *prev;		/* local node */
	prev = NULL;				/* a struct pointer to point to previous node */
	temp = head;				
	if(temp == NULL){			/* if the list is empty then make a node */
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = n;
		temp->next = NULL;
		head = temp;
		return;
	}
	else if(temp->next == NULL){		/* if list has single node then comapre data with that node */
		if(n<temp->data){
			//printf("If single element in the list, n < temp->data \n");
			Insert_head(n);		/* if data is less than node data insert in begining */
			return;
		}
		else{				
			//printf("If single element in the list, n> temp->data \n");
			Insert_end(n);		/* if data is more than node data insert at end */
			return;
		}
	}
	else{					/* else go through the list and place the data at proper location */
		if(n<temp->data){		/* if the 1st node data is more than inserted data then insert at head */
			Insert_head(n);
			return;
		}
		while(temp!=NULL){		/* traverse through the list and insert before greater node */
			//printf("To insert node in between %d \n", n);
			if(n<temp->data){
				struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
				temp1->data = n;
				temp1->next = temp;
				prev->next = temp1;
				return;
			}
			prev = temp;
			temp=temp->next;
		}
		Insert_end(n);			/* If the inserted data is more than data of all nodes then insert the node at end */
	}
}

void Print(){					/* print the whole list */
	struct Node *temp;
	temp = head;
	while(temp!=NULL){
		printf("%d  ", temp->data);
		temp=temp->next;
	}
}

int main(){
	int i=0,n=0;
	printf("The program to sort while inserting in a linked-list \n");
	printf("Inert 10 elements to populate the list of 10 nodes: \n");
	for(i=0;i<10;i++){			/* make a linked list of 10 nodes */
		printf("Enter node: ");		
		scanf("%d", &n);		/* Prompt to user for inserting the node */
		Insert(n);			/* invoke the insert function */
	}
	Print();				/* Print the whole list */
	return 0;
}