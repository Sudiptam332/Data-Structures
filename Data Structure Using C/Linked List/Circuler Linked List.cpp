// circuler Linked List by Maintaining Head pointer
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

void insertAtFirst(struct node ** head, int data){
	struct node * ptr = *head;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	if(!*head){
		newNode->next = *head;
		*head = newNode;
	}
	else{
		while(ptr->next != *head){
			ptr = ptr->next;
		}
		newNode->next = *head;
		ptr->next = newNode;
		*head = newNode;
	}
}

void insertAtLast(struct node ** head, int data){
	struct node * ptr = *head;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	if(!*head){
		newNode->next = *head;
		*head = newNode;
	}
	else{
		while(ptr->next != *head){
			ptr = ptr->next;
		}
		newNode->next = *head;
		ptr->next = newNode;
	}
}

//struct node * insertAtLast(struct node * head, int data){
//	struct node * ptr = head;
//	struct node * newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->data = data;
//	
//	if(!head){
//		newNode->next = head;
//		head = newNode;
//	}
//	else{
//		while(ptr->next != head){
//			ptr = ptr->next;
//		}
//		newNode->next = ptr->next;
//		ptr->next = newNode;
//	}
//	return head;
//}

void display(struct node * head){
	struct node * ptr = head;
	while(ptr->next != head){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("%d ",ptr->data);
}

int main(){
	struct node * head = (struct node *)malloc(sizeof(struct node));
	struct node * second = (struct node *)malloc(sizeof(struct node));
	struct node * third = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = head;
	
	int data;
	scanf("%d",&data);
	insertAtFirst(&head,data);
//	insertAtLast(&head,data);

	display(head);
	
//	while(choice){
//		int data;
//		scanf("%d",&data);
//		insertAtLast(&head,data);
//		scanf("%d", &choice);
//	}
}
