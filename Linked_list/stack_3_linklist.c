/* Linked list implemetation of stack */

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *top = NULL;

void push(int x){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = top;
	top = temp;
}

void pop(){
	struct Node *temp;
	if(top==NULL) return;
	temp = top;
	top = top->next;
	free(temp);
}

void Top(){
	struct Node *temp;
	temp = top;
	printf("%d  \n",temp->data);
}


void Print(){
	struct Node *temp; 
	temp = top;
	while(temp != NULL){
		printf("%d  ", temp->data);
		temp=temp->next;
	}
}

void is_Empty(){
	if(top==NULL){
		printf("The stack is empty \n");
	}
	else{
		printf("The stack is not empty \n");
	}
}

int main(){
	is_Empty();
	push(2);
	Top();
	push(3);
	Top();
	push(4);
	Top();
	push(5);
	Top();
	pop();
	is_Empty();
	pop();
	is_Empty();
	pop();
	is_Empty();
	pop();
	is_Empty();
	//pop();
	Print();
	return 0;
}