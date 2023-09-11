#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * reverse(struct node * head){
	struct node * prev = head;
	struct node * current = head->next;
	struct node * nextNode = current->next;
	prev->next = NULL;
	while(nextNode != NULL){
		current->next = prev;
		prev = current;
		current = nextNode;
		nextNode = current->next;
	}
	current->next = prev;
	head = current;
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
	struct node * fourth = (struct node *)malloc(sizeof(struct node));
	struct node * fifth = (struct node *)malloc(sizeof(struct node));
	struct node * sixth = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = sixth;
    sixth->data = 60;
    sixth->next = NULL;
    
    head = reverse(head);
    traverse(head);
}
