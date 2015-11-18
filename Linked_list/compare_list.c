#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void Print(struct Node *p){
	if(p == NULL){
		return;
	}
	printf("%d \n", p->data);
	Print(p->next);
}

int compare(struct Node *headA, struct Node* headB)
{
    struct Node *temp1, *temp2;
	
	temp1 = headA;
	temp2 = headB;
    int count_data = 0;
    int count_nodeA = 0;
    int count_nodeB = 0;
    if((headA==NULL)&&(headB==NULL)){
        return 1;
    }
	while((temp1!=NULL)&&(temp2!=NULL)){    
		if((temp1->data)!=(temp2->data)){
			count_data++;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
    temp1 = headA;
	temp2 = headB;
    while((temp1!=NULL)){
        count_nodeA++;
        temp1 = temp1->next;
    }
    while((temp2!=NULL)){
        count_nodeB++;
        temp2 = temp2->next;
    }
    if((count_nodeA == count_nodeB)&&(count_data==0)){
        return 1;
    }
    else{
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
	for(i=0;i<10;i++){
		printf("Enter data for 1st list: \n");
		scanf("%d", &data);
		head1 = Insert_end(head1, data);
	}
	
	printf("Start entering data for second list: \n");
	for(i=0;i<10;i++){
		printf("Enter data for 2nd list: \n");
		scanf("%d", &data);
		head2 = Insert_end(head2, data);
	}
	Print(head1);
	Print(head2);
	result = compare(head1, head2);
	if(result == 1){
		printf("True");
	}
	else{
		printf("False");
	}
}