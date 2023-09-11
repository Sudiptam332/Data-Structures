#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * prev;
	struct node * next;
};

void insertAtBegining(struct node ** head, struct node ** tail, int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	
	if(*head == NULL){
		newNode->next = newNode;
		newNode->prev = newNode;
		*head = *tail = newNode;
	}
	else{
		newNode->next = (*head);
		newNode->prev = (*tail);
		(*tail)->next = newNode;
		(*head)->prev = newNode;
		(*head) = newNode;
	}
}

void insertAtPosition(struct node * head, int data, int pos){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;

	struct node * ptr = head;
	while(pos-1 > 1){
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	newNode->prev = ptr;
	ptr->next = newNode;

}

void insertAfterNode(struct node * head, int data, struct node * ptr){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;

	newNode->next = ptr->next;
	newNode->prev = ptr;
	ptr->next = newNode;

}

void insertAtLast(struct node ** head, struct node ** tail, int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	
	if(*head == NULL){
		newNode->next = newNode;
		newNode->prev = newNode;
		*head = *tail = newNode;
	}
	else{
		newNode->next = (*tail)->next;
		newNode->prev = *tail;
		(*tail)->next = newNode;
		(*tail) = newNode;
	}
}

void display(struct node * head, struct node * tail){
	struct node * ptr = head;
	while(ptr->next != head){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("%d ",ptr->data);
}

int main(){
//	struct node * head = NULL;
//	struct node * tail = NULL;
	struct node * head = (struct node *)malloc(sizeof(struct node));
	struct node * second = (struct node *)malloc(sizeof(struct node));
	struct node * third = (struct node *)malloc(sizeof(struct node));
	struct node * tail = third;
    head->data = 10;
    head->prev = tail;
    head->next = second;
    second->data = 20;
    second->prev = head;
    second->next = third;
    third->data = 30;
    third->prev = second;
    third->next = head;
    
//	insertAtBegining(&head, &tail, 5);
//	insertAtPosition(head, 8, 2);
	insertAfterNode(head, 57, second);
//	insertAtLast(&head, &tail, 7);

	display(head, tail);
}
