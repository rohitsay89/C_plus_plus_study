#include <stdio.h>
#define SIZE	5
int arr[SIZE];
int top=SIZE-1;
int i=0;

void pop(){
	top++;
	printf("The top is at: %d \n", top);
}

void push(){
	int num=0;
	printf("This is push operation, enter a number to push on the stack:\n");
	scanf("%d", &num);
	printf("The top is at: %d", top);
	arr[top]=num;
	top--;
	for(i=0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	printf("Program to show stack data structure : \n");
	push();
	push();
	push();
	push();
	push();
	
	pop();
	pop();
	pop();
	pop();
	pop();
	
	for(i=0;i<SIZE;i++){
		printf("%d  \t",arr[i]);
	}
	printf("\n");
	return 0;
}


