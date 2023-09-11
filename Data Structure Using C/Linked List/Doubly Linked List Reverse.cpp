#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * prev;
	struct node * next;
};

void reverse(struct node * head, struct node * tail){
	struct node * ptr = head;
	struct node * ptr2 = tail;
	struct node * ptr3 = tail;
	head = ptr2;
	ptr3->prev = NULL;
	
	while(ptr2->prev != tail){
		ptr2 = ptr2->prev;
		ptr3->next = ptr3->prev;
		ptr2->next = ptr3;
		ptr3 = ptr3->next;
	}
	ptr3->next = NULL;
	
	tail = ptr3;
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

    display(head);
    reverse(head, tail);
    display(head);
    return 0;
}
