#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node * link;
}queue;

queue * front=0, * rear=0;

void enqueue(int val){
	queue * newNode = (queue *)malloc(sizeof(queue));
	newNode->data = val;
	newNode->link = NULL;
	
	if(front == 0 && rear == 0){
		front = rear = newNode;
	}
	else{
		rear->link = newNode;
		rear = newNode;
	}
}

int dequeue(){
	if(front == 0 && rear == 0){
		printf("Queue is Empty\n");
		return -1;
	}
	else if(front == rear){
		queue * temp = front;
		int num = temp->data;
		front = rear = NULL;
		return num;
	}
	else{
		queue * temp = front;
		int num = temp->data;
		front = front->link;
		free(temp);
		return num;
	}
}

int peek(){
	if(front == 0 && rear == 0){
		printf("Queue is Empty\n");
	}
	else{
		return front->data;
	}
}

void display(){
	if(front == 0 && rear == 0){
		printf("Queue is Empty\n");
	}
	else{
		queue * ptr = front;
		printf("Queue Elements : ");
		while(ptr != rear){
			printf("%d ",ptr->data);
			ptr = ptr->link;
		}
		printf("%d ",ptr->data);
		printf("\n");
	}
}

int main(){
	int choose, val;
	while(1){
		printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
		printf("Enter Your choice : ");
		scanf("%d",&choose);
		
		switch(choose){
			case 1 :	printf("\nEnter the value : ");
						scanf("%d",&val);
						enqueue(val);
						break; 
					
			case 2 : 	int num;
						num = dequeue();
						printf("%d Dequeue\n",num);
						break;
			
			case 3 :	num = peek();
						printf("Peek : %d\n",num);
						break;
			
			case 4 :	display();
						break;
						
			case 5 :	exit(0);
					
		}
	}
}
