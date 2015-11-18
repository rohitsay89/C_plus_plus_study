/*
  This code is written for comparing two linked lists and print "True" if 
  list is identical or else print "False"
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void Print(struct Node *p){					/* Function to print list */
	if(p == NULL){
		return;
	}
	printf("%d \n", p->data);
	Print(p->next);						/* Recursive function call */
}

int compare(struct Node *headA, struct Node* headB){		/* function to compare two linked list and output 1 or 0 */
	struct Node *temp1, *temp2;
	
	temp1 = headA;
	temp2 = headB;
	int count_data = 0;
	int count_nodeA = 0;
	int count_nodeB = 0;
	if((headA==NULL)&&(headB==NULL)){				/* Check if both of the lists are empty */
		return 1;						/* If yes then return 1 */
    	}
	while((temp1!=NULL)&&(temp2!=NULL)){    		/* Traverse through both the lists and compare data */
		if((temp1->data)!=(temp2->data)){		/* If data is not same */
			count_data++;				/* increment count */
			if(count_data>0){			/* Check if count is more than 0 */
				return 0;			/* If yes then retrun 0 to main function i.e. list is not idnetical*/
			}
		}
		temp1=temp1->next;				/* go to next node for list 1 */
		temp2=temp2->next;				/* go to next node for list 2 */
	}
	temp1 = headA;						
	temp2 = headB;
    	while((temp1!=NULL)){					/* Check for lenght of linked lists */
        	count_nodeA++;					/* count the length */
		temp1 = temp1->next;
	}
	while((temp2!=NULL)){
		count_nodeB++;					/* Check for lenght of linked lists */
		temp2 = temp2->next;				/* count the length */
    	}
    	if((count_nodeA == count_nodeB)&&(count_data==0)){	/* if length and data is equal then return 1 */
        	return 1;
    	}
    	else{							/* Else return 0 */
        	return 0;
    	}
}

struct Node* Insert_end(struct Node *head, int data){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}
	else{
		struct Node *temp1;
		temp1=head;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next = temp;
	}
	return head;
}

void main(){
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;
	int result=0;
	printf("Program to comapre 2 linked list \n");
	int data = 0, i = 0;
	printf("Start entering data for first list: \n");
	for(i=0;i<10;i++){					/* Fill the 1 list */
		printf("Enter data for 1st list: \n");
		scanf("%d", &data);
		head1 = Insert_end(head1, data);
	}
	
	printf("Start entering data for second list: \n");
	for(i=0;i<10;i++){					/* Fill the 1 list */
		printf("Enter data for 2nd list: \n");
		scanf("%d", &data);
		head2 = Insert_end(head2, data);
	}
	Print(head1);						/* print the 1 list */
	Print(head2);						/* print the 1 list */
	result = compare(head1, head2);				/* pass head for both list to compare function and save result in a variable */
	if(result == 1){
		printf("True");					/* Print True if list is same */
	}
	else{
		printf("False");				/* Print False if list is same */
	}
}