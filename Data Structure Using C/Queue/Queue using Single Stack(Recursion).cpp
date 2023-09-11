#include<stdio.h>
#include<stdlib.h> 
#define N 5

int top = -1;
int stack[N];

int isEmpty(){
	if(top == -1){
		return 1;
	}
	return 0;
}

int isFull(){
	if(top == N){
		return 1;
	}
	return 0;
}

void push(int val){
	if(isFull()){
		printf("Stack Full\n");
	}
	else{
		top++;
		stack[top] = val;
	}
}

int pop(){
	int val = -1;
	if(isEmpty()){
		printf("Stack Empty\n");
	}
	else{
		val = stack[top];
		top--;
	}
	return val;
}

int peek(){
	if(isEmpty()){
		printf("Stack Empty\n");
		return -1;
	}
	return stack[0];
}

void enqueue(int val){
	push(val);
}

int dequeue(){
	if(top == 0){
		return stack[top+1];
	}
	else if(top == -1){
		printf("Queue Empty\n");
		return -1;
	}
	top--;
	stack[top] = dequeue();
	top++;
	int val = stack[top+1];
	
	return val;
}

void display(){
	if(isEmpty()){
		printf("Stack Empty\n");
	}
	else{
		printf("Stack elements are : ");
		for(int i=0; i<=top; i++){
			printf("%d ",stack[i]);
		}
	}
	printf("\n");
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
						num = stack[0];
						dequeue();
						top--;
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
