#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};

struct node * insert_At_Begining(struct node * head, int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	return head;
}

struct node * insert_At_Index(struct node * head, int data, int index){
	struct node * ptr = head;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	while(index-1 != 1){
		ptr = ptr->next;
		index--;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
	return head;
}

struct node * insert_At_Last(struct node * head, int data){
	struct node * ptr = head;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = newNode;
	return head;
}

struct node * insert_After_Node(struct node * head, int data, struct node * node){
	struct node * ptr = head;
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = node->next;
	node->next = newNode;
	return head;
}

void traverse(struct node * head){
	struct node * ptr = head;
	while(ptr != NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
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
    third->next = NULL;
    int data;
    scanf("%d",&data);
//    head = insert_At_Begining(head, data);
    head = insert_At_Index(head, data, 2);
//    head = insert_At_Last(head, data);
//    head = insert_After_Node(head, data , second);
    traverse(head);
    return 0;
}
