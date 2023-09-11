// circuler Linked List Deletion 
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

void deleteFirst(struct node ** tail){
	struct node * temp = (*tail)->next;
	(*tail)->next = temp->next;
	free(temp);
}

void deletePosition(struct node ** tail, int pos){
	struct node * ptr = (*tail)->next;
	while(pos-1 != 1){
		ptr = ptr->next;
		pos--;
	}
	struct node * temp = ptr->next;
	ptr->next = temp->next;
	free(temp);
}

void deleteLast(struct node ** tail){
	struct node * temp = *tail;
	struct node * ptr = *tail;
	while(ptr->next != *tail){
		ptr = ptr->next;
	}
	ptr->next = (*tail)->next;
	*tail = ptr;
	free(temp);
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

//	deleteFirst(&tail);
	deletePosition(&tail, 2);
//	deleteLast(&tail);

	display(tail);
	
}
