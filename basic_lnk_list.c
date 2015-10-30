/*
* Code for inserting data at the begining and end of a linked list
* By: Rohit Deshpande
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{				/* Declare a structure */
	int data;				/* declare its elements */
	struct Node* next;		
};
struct Node* head;			/* Declare a head pointer */

/* Function prototype */
void Print();				/* Function to print entire list */
void Insertb();				/* Function to append data at begining of list */
void Insertn();				/* Function to append data at nth position in list */
void Inserte();				/* Function to append data at end of list */

void Insertb(int data){		/* Function to insert value in begining */
	struct Node* temp;		/* declare a new pointer to structure variable(Node) */
	temp = (struct Node*)malloc(sizeof(struct Node));	/* Allocate memory to it */
	temp->data = data;		/* insert data in the new node */
	temp->next = head;		/* break the old link and link the new node with old node */
	head = temp;			/* save the new node in head of list */
}

void Inserte(int data){		/* function to insert value at end of list  */
	struct Node* temp;		/* declare a new pointer to structure variable(Node) */
	temp = head;			/* save the address of head in new node 'temp' */
	
	if(temp==NULL){
		temp = (struct Node*)malloc(sizeof(struct Node));	/* Allocate memory to it */
		temp->data=data;	/* insert data in new node */
		temp->next=NULL;	/* Point it to null as it is the end node */
		head = temp;		/* store its addess to head as it is the first node in the list */
		return;				/* Don't execute further just return to the flow */
	}
	
	while(temp->next!=NULL){/* traverse the list till end */
		temp=temp->next;	/* store the last node in temp */
	}
	struct Node* temp1;		/* declare a new pointer to structure variable(Node) */
	temp1 = (struct Node*)malloc(sizeof(struct Node));/* then make a new node 'temp1' */
	temp->next = temp1;		/* point new node to old node i.e. 'temp1' ==> 'temp' */
	temp1->data = data;		/* insert data */
	temp1->next = NULL;		/* point the new node to NULL i.e. end of list */
}
void Insertn(int p, int data){
	struct Node* temp1;		/* declare a new pointer to structure variable(Node) */
	struct Node* temp2;		/* declare a new pointer to structure variable(Node) */
	temp2 = (struct Node*)malloc(sizeof(struct Node)); /* Allocate memory to node */
	temp2->data = data;		/* insert data in node */
	temp2->next = NULL;		/* point it to null */
	int i=0;
	
	if(p==1){				/* for case if position is 1st */
		Insertb(data);		/* Isert in begining */
	}
	else{					/* Otherwise insert at nth position */
		temp1=head;			/* traverse through the list */
		for(i=1;i<p-1;i++){
			temp1=temp1->next;
		}
		temp2->next = temp1->next;	/* store link of old node to link of new node */
		temp1->next=temp2;			/* store new node address to link of previous node */
	}
}
void Print(){				/* function to print a list */
	struct Node* temp = head;
	while(temp!=NULL){		/* Traverse through each node and print it */
		printf("%d ",temp->data);
		printf("%d \n",temp->next);
		temp=temp->next;	/* then point to next node */
	}
	printf("\n");			
}

int main(){
	head = NULL;			/* define the value of head as NULL */
	int i=0,x=0,n=0,p=0;	/* initialize variables used */
	printf("How many numbers ? \n");
	scanf("%d", &n);		/* input number of elements to insert by user */
	
	for(i=0;i<n;i++){		/* loop for inseting at the end */
		printf("Enter data to insert at end: \n");
		scanf("%d", &x);
		Inserte(x);			/* Call insert begining function and pass value from user */
	}
	Print();				/* Print the whole list */
	printf("Enter a node at nth position in list \n");
	printf("Enter the nth position: \n");
	scanf("%d", &p);		/* Read position from user */
	printf("Enter the data to be inserted: \n");
	scanf("%d", &x);		/* Read data from user */
	Insertn(p,x);			/* Execute the Function to insert data at nth position */
	Print();				/* Print the entire list */
	return 0;
}
