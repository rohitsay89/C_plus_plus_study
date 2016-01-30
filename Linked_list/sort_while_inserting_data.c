/* sorting while inserting in a linked list */
/* Made from scratch */

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void Insert_head(int n){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = head;
	head = temp;
	//printf("inserted data at end is: %d \n", temp->data);
}

void Insert_end(int n){
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

void Insert(int n){
	int pos=0, i=0;
	struct Node *temp, *prev;
	prev = NULL;
	temp = head;
	if(temp == NULL){
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = n;
		temp->next = NULL;
		head = temp;
		return;
	}
	else if(temp->next == NULL){
		if(n<temp->data){
			//printf("If single element in the list, n < temp->data \n");
			Insert_head(n);
			return;
		}
		else{
			//printf("If single element in the list, n> temp->data \n");
			Insert_end(n);
			return;
		}
	}
	else{
		if(n<temp->data){
			Insert_head(n);
			return;
		}
		while(temp!=NULL){
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
		Insert_end(n);
	}
}

void Print(){
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
	for(i=0;i<10;i++){
		printf("Enter node: ");
		scanf("%d", &n);
		Insert(n);
	}
	Print();
	return 0;
}