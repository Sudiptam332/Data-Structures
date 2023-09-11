// circuler Linked List by Maintaining tail pointer
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

void insertAtFirst(struct node ** tail, int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	if(!*tail){
		newNode->next = *tail;
		*tail = newNode;
	}
	else{
		newNode->next = (*tail)->next;
		(*tail)->next = newNode;
	}
}

void insertAtPosition(struct node ** tail, int data, int pos){
	struct node * ptr = (*tail)->next;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	
	while(pos-1 != 1){
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
}


void insertAtLast(struct node ** tail, int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	if(!*tail){
		newNode->next = *tail;
		*tail = newNode;
	}
	else{
		newNode->next = (*tail)->next;
		(*tail)->next = newNode;
		*tail = newNode;
	}
}


void display(struct node * tail){
	struct node * ptr = tail->next;
	while(ptr != tail){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("%d ",ptr->data);
}

int main(){
	struct node * first = (struct node *)malloc(sizeof(struct node));
	struct node * second = (struct node *)malloc(sizeof(struct node));
	struct node * tail = (struct node *)malloc(sizeof(struct node));
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = tail;
    tail->data = 30;
    tail->next = first;
	
	int data;
	scanf("%d",&data);
//	insertAtFirst(&tail,data);
	insertAtPosition(&tail, data, 2);
//	insertAtLast(&tail,data);

	display(tail);
	
}
