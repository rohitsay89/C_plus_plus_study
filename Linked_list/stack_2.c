#include <stdio.h>
#define SIZE	5
int arr[SIZE];
int i=0;
int top=-1;

void pop(){
	if(top==-1){
		printf("Error: No element to pop \n");
		return;
	}
	top=top-1;
	
	printf("The top is at: %d \n", top);
}

void push(){
	int num=0;
	printf("This is push operation, enter a number to push on the stack:\n");
	scanf("%d", &num);
	top=top+1;
	printf("The top is at: %d", top);
	arr[top]=num;
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
	printf("The top is at: %d \n", top);
	for(i=0;i<SIZE;i++){
		printf("%d  \t",arr[i]);
	}
	printf("\n");
	return 0;
}