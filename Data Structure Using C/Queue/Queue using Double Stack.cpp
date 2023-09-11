#include<stdio.h>
#include<stdlib.h>
#define N 5
int top1 = -1, top2 = -1, count = 0;
int stack1[N], stack2[N];

bool isEmpty1(){
	if(top1 == -1){
		return true;
	}
	return false;
}

bool isFull1(){
	if(top1 == N){
		return true;
	}
	return false;
}

bool isEmpty2(){
	if(top2 == -1){
		return true;
	}
	return false;
}

bool isFull2(){
	if(top2 == N){
		return true;
	}
	return false;
}

void push1(int val){
	if(isFull1()){
		printf("Stack Full\n");
	}
	else{
		top1++;
		stack1[top1] = val;
	}
}

int pop1(){
	int val = -1;
	if(isEmpty1()){
		printf("Stack Empty\n");
	}
	else{
		val = stack1[top1];
		top1--;
	}
	return val;
}

void push2(int val){
	if(isFull2()){
		printf("Stack Full\n");
	}
	else{
		top2++;
		stack2[top2] = val;
	}
}

int pop2(){
	int val = -1;
	if(isEmpty2()){
		printf("Stack Empty\n");
	}
	else{
		val = stack2[top2];
		top2--;
	}
	return val;
}

int peek(){
	if(isEmpty1()){
		printf("Stack Empty\n");
		return -1;
	}
	return stack1[0];
}

void display(){
	if(isEmpty1()){
		printf("Stack Empty\n");
	}
	else{
		printf("Stack elements are : ");
		for(int i=0; i<=top1; i++){
			printf("%d ",stack1[i]);
		}
	}
	printf("\n");
}

void enqueue(int val){
	push1(val);
	count++;
}

int dequeue(){
	if(isEmpty1()){
		printf("Queue is Empty\n");
		return -1;
	}
	else{
		int i = 0;
		while(i < count){
			int val = pop1();
			push2(val);
			i++;
		}
		int num = pop2();
		count--;
		i = 0;
		while(i < count){
			int val = pop2();
			push1(val);
			i++;
		}
		return num;
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
