#include <iostream>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node *top=NULL;

void Push(int n){
	struct Node *temp;
	temp = new struct Node;
	temp->data = n;
	
	if(top==NULL){	
		temp->next = NULL;
	}
	else{
		temp->next = top;
	}
	top = temp;
}

void Pop(){
	
}

void Top(){
	struct Node *temp;
	temp = top;
	cout << "the top is : " << temp->data << endl;
}

void Print(){
	struct Node *temp;
	temp = top;
	while(temp != NULL){
		cout << temp->data << "  ";
		//printf("%d  ", temp->data);
		temp=temp->next;
	}
	cout << endl;
}

void is_Empty(){
	
}

int main(){
	//printf("Program for creating a stack using linked list in c plus plus \n");
	cout << "Program for creating a stack using linked list in c plus plus \n";
	
	Push(5);
	Push(4);
	Push(3);
	Top();
	Push(2);
	Push(1);
	
	Print();
	return 0;
}