/* Basic linked list implementation using classes and objects */

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Node{					/* Make a class */
public:						
	int data;				/* data */
	Node *next;				/* Pointer to next object */
};

Node *head = NULL;				/* Head of the linked list */
						/* initially pointed to NULL */

void Insert_beg(int n){				/* Inert function */
	if(head == NULL){			/* First case if list is empty */
		Node *temp = new Node;		/* Create a new object(node) */
		temp->data = n;			/* insert data */
		temp->next = NULL;		/* Point it to NULL */
		head = temp;			/* Point the head to new node */
	}
	else{					/* If list is not empty */
		Node *temp = new Node;		/* create a new node */
		temp->data = n;			/* Insert data */
		temp->next = head;		/* link the old node with new node */
		head = temp;			/* link head with new node */
	}
	
}

void Print(){					/* Function to print the list */
	Node *temp;				/* Creat a temporary node */
	temp = head;				/* point to the first node of list */
	while(temp!=NULL){			/* trvaerse through the list */
		cout << temp->data << "\t";	/* print the data on console */
		temp = temp->next;		/* point to the next node */
	}
	cout << endl;				/* insert a new line after loop */
}

int main(){					
	cout << "The program for writing a linked list using classes" << endl;
	int i=0,num=0;
	cout << "Please enter a number to insert at the start of the list" << endl;
	for(i=0;i<10;i++){			/* loop for taking data from user and entering in the list */
		cout << "Enter a number : ";	
		cin >> num;			/* read input from console */
		Insert_beg(num);		/* call the insert begining function */
		cout << endl;
	}
	Print();				/* Call the print function to print the list */
	return 0;
}
