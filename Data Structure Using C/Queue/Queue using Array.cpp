#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front=-1, rear=-1;

void enqueue(int val){
	if(rear == N-1){
		printf("Queue is Full\n");
	}
	else if(front == -1 && rear == -1){
		front = rear = 1;
		queue[rear] = val;
	}
	else{
		rear++;
		queue[rear] = val;
	}
}

int dequeue(){
	if(front == -1 && rear == -1){
		printf("Queue is Empty\n");
	}
	else if(front == rear){
		int num = queue[front];
//		printf("Dequeue : %d\n",num);
		front = rear = -1;
		return num;
	}
	else{
		int num = queue[front];
//		printf("Dequeue : %d\n",num);
		front++;
		return num;
	}
}

int peek(){
	if(front == -1 && rear == -1){
		printf("Queue is Empty\n");
	}
	else{
		return queue[front];
	}
}

void display(){
	if(front == -1 && rear == -1){
		printf("Queue is Empty\n");
	}
	else{
		printf("Queue Elements : ");
		while(front != rear){
			printf("%d ",queue[front]);
			front++;
		}
		printf("%d ",queue[front]);
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
