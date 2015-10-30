/*
* Code for inserting data at the begining and end of a linked list
* By: Rohit Deshpande
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head;

void Print();

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
	printf("inside print insert function");
	struct Node* temp1;
	struct Node* temp2;
	temp2 = (struct Node*)malloc(sizeof(struct Node));
	temp2->data = data;
	temp2->next = NULL;
	int i=0;
	printf("before if-else statement");
	if(p==1){
		Insertb(data);
	}
	else{
		temp1=head;
		for(i=1;i<p-1;i++){
			temp1=temp1->next;
		}
		printf("after for loop");
		temp2->next = temp1->next;
		temp1->next=temp2;
	}
	printf("after else statement");
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
	for(i=0;i<n;i++){		/* loop for inserting in begining */
		printf("Enter data to insert at begining: \n");
		scanf("%d", &x);	
		Insertb(x);			/* Call insert begining function and pass value from user */
	}
	Print();				/* Print the whole list */
	for(i=0;i<n;i++){		/* loop for inseting at the end */
		printf("Enter data to insert at end: \n");
		scanf("%d", &x);
		Inserte(x);			/* Call insert begining function and pass value from user */
	}
	Print();				/* Print the whole list */
	printf("Enter a node at nth position in list");
	printf("Enter the nth position: ");
	scanf("%d", &p);
	printf("Enter the data : ");
	scanf("%d", &x);
	Insertn(p,x);
	Print();
	return 0;
}
