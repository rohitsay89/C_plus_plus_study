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

void Print(){
	struct Node *temp; 
	temp = top;
	while(temp != NULL){
		printf("%d  ", temp->data);
		temp=temp->next;
	}
}

int main(){
	int i=0, n=0;
	push(2);		/* Push 2 on the stack */
	push(3);		/* Push 3 on the stack */
	push(4);		/* Push 4 on the stack */
	push(5);		/* Push 5 on the stack */
	pop();			/* pop from the top */
	//pop();
	Print();		/* Print the whole list */
	return 0;
}
