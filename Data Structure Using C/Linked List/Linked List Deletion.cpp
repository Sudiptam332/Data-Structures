#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};

struct node * delete_from_Begining(struct node * head){
	struct node * temp = head;
	head = head->next;
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
	free(temp);
	return head;
}

struct node * delete_from_Last(struct node * head){
	struct node * ptr = head;
	while(ptr->next->next != NULL){
		ptr = ptr->next;
	}
	struct node * temp = ptr->next;
	ptr->next = NULL;
	free(temp);
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

//    head = delete_from_Begining(head);
    head = delete_from_Index(head, 2);
//    head = delete_from_Last(head);
    traverse(head);
    return 0;
}
