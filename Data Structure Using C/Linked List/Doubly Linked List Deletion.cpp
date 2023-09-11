#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * prev;
	struct node * next;
};

struct node * delete_from_Begining(struct node * head){
	struct node * temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
	return head;
}

struct node * delete_from_Index(struct node * head, int index){
	struct node * ptr = head;
	int i = 0;
	while(i != index-2){
		ptr = ptr->next;
		i++;
	}
	struct node * temp = ptr->next;
	ptr->next = temp->next;
	temp->next->prev = ptr;
	free(temp);
	return head;
}

struct node * delete_from_Last(struct node * tail){
	struct node * temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	free(temp);
	return tail;
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

    head = delete_from_Begining(head);
//    head = delete_from_Index(head, 2);
//    tail = delete_from_Last(tail);
    display(head);
    rev_display(tail);
    return 0;
}
