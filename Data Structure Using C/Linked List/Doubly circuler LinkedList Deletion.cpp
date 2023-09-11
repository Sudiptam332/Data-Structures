#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * prev;
	struct node * next;
};

void deleteFirst(struct node ** head, struct node ** tail){
	if(*head == NULL){
		printf("List Empty");
	}
	else{
		struct node * temp = (*head);
		(*tail)->next = temp->next;
		temp->next->prev = (*tail);
		(*head) = temp->next;
		free(temp); 
	}
}

void delete_from_Index(struct node * head, int index){
	if(head == NULL){
		printf("List Empty");
	}
	else{
		struct node * ptr = head;
		while(index-1 > 1){
			ptr = ptr->next;
		}
		struct node * temp = ptr->next;
		temp->next->prev = ptr;
		ptr->next = temp->next;
		free(temp); 
	}
}

void delete_from_Last(struct node * head, struct node ** tail){
	if(head == NULL){
		printf("List Empty");
	}
	else{
		struct node * temp = (*tail);
		(*tail) = (*tail)->prev;
		(*tail)->next = head;
		head->prev = (*tail);
		free(temp); 
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
    
//	deleteFirst(&head, &tail);
//	delete_from_Index(head, 2);
	delete_from_Last(head, &tail);

	display(head, tail);
}
