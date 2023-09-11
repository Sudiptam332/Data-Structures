// Doubly Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * prev;
	struct node * next;
};

struct node * insert_At_Begining(struct node * head, int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return head;
}

struct node * insert_At_Position(struct node * head, int data, int index){
	struct node * ptr = head;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	
	while(index-1 != 1){
		ptr = ptr->next;
		index--;
	}
	newNode->next = ptr->next;
	newNode->prev = ptr;
	newNode->next->prev = newNode;
	ptr->next = newNode;
	return head;
}

struct node * insert_At_Last(struct node * tail, int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	return tail;
}

struct node * insert_After_Node(struct node * head, int data, struct node * node){
	struct node * ptr = head;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->prev = node;
	newNode->next = node->next;
	newNode->next->prev = newNode;
	node->next = newNode;
	return head;
}

void display(struct node * head){
	struct node * ptr = head;
	while(ptr != NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void rev_display(struct node* tail){
	struct node * ptr = tail;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->prev;
	}
	printf("\n");
}

int main(){
	struct node * head = (struct node *)malloc(sizeof(struct node));
	struct node * second = (struct node *)malloc(sizeof(struct node));
	struct node * third = (struct node *)malloc(sizeof(struct node));
	struct node * tail = third;
    head->data = 10;
    head->prev = NULL;
    head->next = second;
    second->data = 20;
    second->prev = head;
    second->next = third;
    third->data = 30;
    third->prev = second;
    third->next = NULL;
    
    int data;
    printf("Enter the data : ");
    scanf("%d", &data);
    
//    head = insert_At_Begining(head, data);
//    head = insert_At_Position(head, data, 2);
//    tail = insert_At_Last(tail, data);
	head =  insert_After_Node(head,data,second);
    display(head);
    rev_display(tail);
}
